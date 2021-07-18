#pragma once
#include <string>

namespace Crystal
{
	class VertexBuffer
	{
	public:
		VertexBuffer() {};

		virtual void Bind() = 0;
		virtual void UnBind() = 0;
	
		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		IndexBuffer(uint32_t count):m_Count(count) {};

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t size);


		uint32_t Count() const { return m_Count; }
	protected:
		uint32_t m_Count;
	};
}