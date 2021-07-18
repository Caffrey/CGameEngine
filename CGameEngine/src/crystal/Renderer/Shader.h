#pragma once

#include <string>

namespace Crystal
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& pixelSource);
		~Shader();

		void Bind();
		void UnBind();

	private:
		uint32_t m_RendererID;
	};


}