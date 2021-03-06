#pragma once

namespace Crystal
{
	enum class RendererAPI
	{
		None = 0, OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RenderAPI; }


		static RendererAPI s_RenderAPI;
	};
}