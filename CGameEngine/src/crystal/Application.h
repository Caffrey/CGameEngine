#pragma once

#include "Core.h"

#include "crystal/Window.h"
#include "crystal/event/ApplicationEvent.h"
#include "crystal/layer/LayerStack.h"
#include "crystal/imgui/ImguiLayer.h"
#include "crystal/Renderer/Shader.h"
#include "crystal/Renderer/Buffer.h"

namespace Crystal {

	class CRYSTAL_API Application
	{
	public:
		Application();
		~Application();
	
	
		virtual void Run();

		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlayer(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		std::unique_ptr<Window> m_Window;
		ImguiLayer* m_ImguiLayer;

		bool m_IsRunning = false;

		LayerStack m_LayerStack;

		static Application* s_Instance;

		unsigned int m_vertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

	};


	

	Application* CreateAppllication();
}