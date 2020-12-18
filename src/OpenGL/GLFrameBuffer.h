#pragma once
#include <glad/glad.h>

namespace Ciri
{
	struct FrameBufferData
	{
		uint32_t Width = 0, Height = 0;
		uint32_t TextureWidth = 0, TextureHeight = 0;
		uint8_t* ImageData = nullptr;
	};

	class FrameBuffer
	{
	private:
		GLuint m_BufferID = 0, m_ColorAttachment = 0, m_DepthAttachment = 0;
		FrameBufferData m_FrameBufferData;

	public:
		FrameBuffer(const FrameBufferData& data);
		~FrameBuffer();

		void Bind();
		void Unbind();

		void Recreate();
		void Refresh();
		void Resize(uint32_t width, uint32_t height);

		uint32_t GetFrameBufferColorData() const { return m_ColorAttachment; };
		uint32_t GetFrameBufferDepthData() const { return m_DepthAttachment; };
		const FrameBufferData& GetFrameBufferData() const { return m_FrameBufferData; };

	};
}