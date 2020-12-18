#include <ciripch.h>
#include "Gpu.h"

namespace Ciri
{

	size_t GPU::s_TileSize = 16;
	size_t GPU::s_NumTiles = 384;

	GPU::GPU(MemoryUnit& memoryunit, uint32_t screenWidth, uint32_t screenHeight)
		: m_MemoryUnit(memoryunit)
	{
		//srand(std::time(nullptr));
		m_ColorSpace = new uint8_t[4]{ 0x00, 0x55, 0xAA, 0xFF };

		m_FBOData.Width = screenWidth;
		m_FBOData.Height = screenHeight;
		m_FBOData.TextureWidth = 160;
		m_FBOData.TextureHeight = 144;

		m_FBOData.ImageData = new uint8_t[(160 * 144) * 3];
		m_FBO = new FrameBuffer(m_FBOData);

		Update();
	}

	GPU::~GPU()
	{
		delete m_FBO;
		delete m_FBOData.ImageData;
		delete m_ColorSpace;
	}

	void GPU::Update()
	{
		// Fill Video RAM with random grey data
		//for (int i = 0; i < (160 * 144) * 3; i+=3)
		//{
		//	int r = rand();
		//	m_FBOData.ImageData[i] = m_ColorSpace[r % 4];
		//	m_FBOData.ImageData[i + 1] = m_ColorSpace[r % 4];
		//	m_FBOData.ImageData[i + 2] = m_ColorSpace[r % 4];
		//}

		UnpackTileData();
		m_FBO->Refresh();
	}

	void GPU::UnpackTileData()
	{
		uint8_t* vRAM = m_MemoryUnit.getRawVRAM();
		for (size_t tileX = 0; tileX < 20; tileX++)
		{
			for (size_t tileY = 0; tileY < 18; tileY++)
			{
				for (size_t row = 0; row < 8; row++)
				{
					uint8_t color = 0x00;
					size_t tile = tileX + (20*tileY);
					uint8_t byte1 = vRAM[(tile * s_TileSize) + (row * 2)];
					uint8_t byte2 = vRAM[(tile * s_TileSize) + (row * 2) + 1];
					for (size_t pixel = 0; pixel < 8; pixel++)
					{
						// Retrieve the color index for this pixel
						color |= ((byte1 & (1 << pixel)) >> pixel);
						color |= ((byte2 & (1 << pixel)) >> (pixel - 1));
		
						// Update the corresponding pixel
						size_t pixelX = (tileX * 8) + pixel;
						size_t pixelY = (tileY * 8) + row;
						size_t pixelIndex = (pixelX + (160 * pixelY)) * 3;
						//size_t pixelIndex = ((tileY * 64 * 18) + (tileX * 8) + (row * 160) + pixel) * 3;
		
						if (pixelIndex > ((160 * 144) * 3)) { CI_CRITICAL("OOB Pixel | Index: {5}, Tile: {0}, TileX: {1}, TileY: {2}, Row: {3}, Pixel: {4}", tile, tileX, tileY, row, pixel, pixelIndex); }
		
						m_FBOData.ImageData[pixelIndex] = m_ColorSpace[color];
						m_FBOData.ImageData[pixelIndex + 1] = m_ColorSpace[color];
						m_FBOData.ImageData[pixelIndex + 2] = m_ColorSpace[color];
					}
				}
			}
		}
	}
}