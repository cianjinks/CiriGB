#pragma once
#include "OpenGL/GLFrameBuffer.h"

namespace Ciri
{
	class GPU
	{
	private:
		FrameBufferData m_FBOData;
		FrameBuffer* m_FBO;
		unsigned char* m_ColorSpace;

	public:
		GPU(uint32_t screenWidth, uint32_t screenHeight);
		~GPU();

		void Update();

		uint64_t GetGLTexture() { return m_FBO->GetFrameBufferColorData(); }
	};
}