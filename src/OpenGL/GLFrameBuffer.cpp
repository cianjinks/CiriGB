#include <ciripch.h>
#include "GLFrameBuffer.h"

namespace Ciri
{
	FrameBuffer::FrameBuffer(const FrameBufferData& data)
		: m_FrameBufferData(data)
	{
		Recreate();
	}

	FrameBuffer::~FrameBuffer()
	{
		glDeleteFramebuffers(1, &m_BufferID);
		glDeleteTextures(1, &m_ColorAttachment);
		glDeleteTextures(1, &m_DepthAttachment);
	}

	void FrameBuffer::Bind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_BufferID);
		glViewport(0, 0, m_FrameBufferData.Width, m_FrameBufferData.Height);
	}

	void FrameBuffer::Unbind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void FrameBuffer::Recreate()
	{
		if (m_BufferID)
		{
			glDeleteFramebuffers(1, &m_BufferID);
			glDeleteTextures(1, &m_ColorAttachment);
			glDeleteTextures(1, &m_DepthAttachment);
		}

		glCreateFramebuffers(1, &m_BufferID);
		glBindFramebuffer(GL_FRAMEBUFFER, m_BufferID);

		glCreateTextures(GL_TEXTURE_2D, 1, &m_ColorAttachment);
		glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);
		// Note we use 24 bits per pixel which could be much lower
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, m_FrameBufferData.TextureWidth, m_FrameBufferData.TextureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_FrameBufferData.ImageData);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttachment, 0);

		glCreateTextures(GL_TEXTURE_2D, 1, &m_DepthAttachment);
		glBindTexture(GL_TEXTURE_2D, m_DepthAttachment);
		glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH24_STENCIL8, m_FrameBufferData.TextureWidth, m_FrameBufferData.TextureHeight);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_DepthAttachment, 0);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		{
			CI_CRITICAL("Framebuffer is incomplete!");
		}

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void FrameBuffer::Refresh()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_BufferID);

		glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);
		// Note we use 24 bits per pixel which could be much lower
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, m_FrameBufferData.TextureWidth, m_FrameBufferData.TextureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_FrameBufferData.ImageData);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttachment, 0);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void FrameBuffer::Resize(uint32_t width, uint32_t height)
	{
		m_FrameBufferData.Width = width;
		m_FrameBufferData.Height = height;

		Recreate();
	}
}