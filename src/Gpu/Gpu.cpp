#include <ciripch.h>
#include "Gpu.h"

namespace Ciri
{
	GPU::GPU(uint32_t screenWidth, uint32_t screenHeight)
	{
		m_FBOData.Width = screenWidth;
		m_FBOData.Height = screenHeight;
		m_FBOData.TextureWidth = 160;
		m_FBOData.TextureHeight = 144;

		
		srand(std::time(nullptr));
		m_ColorSpace = new unsigned char[4]{ 0x00, 0x55, 0xAA, 0xFF };

		m_FBOData.ImageData = new unsigned char[(160 * 144) * 3];
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
		for (int i = 0; i < (160 * 144) * 3; i+=3)
		{
			int r = rand();
			m_FBOData.ImageData[i] = m_ColorSpace[r % 4];
			m_FBOData.ImageData[i + 1] = m_ColorSpace[r % 4];
			m_FBOData.ImageData[i + 2] = m_ColorSpace[r % 4];
		}
		m_FBO->Refresh();
	}
}