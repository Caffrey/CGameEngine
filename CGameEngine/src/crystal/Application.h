#pragma once

#include "Core.h"

#include "crystal/Window.h"
#include "crystal/event/ApplicationEvent.h"
#include "crystal/layer/LayerStack.h"


namespace Crystal {

	class CRYSTAL_API Application
	{
	public:
		Application();
		~Application();
	
	
		virtual void Run();

		void OnEvent(Event& e);
		void OnWindowClose(WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlayer(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = false;

		LayerStack m_LayerStack;

		static Application* s_Instance;

	};


	

	Application* CreateAppllication();
}