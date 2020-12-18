#pragma once
#include "OpenGL/GLFrameBuffer.h"
#include "Memory/MemoryUnit.h"

namespace Ciri
{
	class GPU
	{
	private:
		static size_t s_TileSize;
		static size_t s_NumTiles;

	private:
		FrameBufferData m_FBOData;
		FrameBuffer* m_FBO;
		MemoryUnit& m_MemoryUnit;
		uint8_t* m_ColorSpace;

	private:
		void UnpackTileData();

	public:
		GPU(MemoryUnit& memoryunit, uint32_t screenWidth, uint32_t screenHeight);
		~GPU();

		void Update();

		uint64_t GetGLTexture() { return m_FBO->GetFrameBufferColorData(); }
	};
}