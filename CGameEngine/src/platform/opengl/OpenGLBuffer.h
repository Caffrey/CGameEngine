#pragma once

#include <string>
#include "crystal/Renderer/Buffer.h"

namespace Crystal
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();
		virtual void Bind() override ;
		virtual void UnBind() override;

		uint32_t m_RendererID;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();
		virtual void Bind() override;
		virtual void UnBind() override;

		uint32_t m_RendererID;

	};
}