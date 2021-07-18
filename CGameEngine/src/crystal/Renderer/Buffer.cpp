#include "cpch.h"
#include "Buffer.h"

#include "crystal/Renderer/Renderer.h"
#include "platform/opengl/OpenGLBuffer.h"


namespace Crystal
{

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:

			break;

		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
				break;
		}

		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:

			break;

		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer (indices, size);
			break;
		}

		return nullptr;
	}

}