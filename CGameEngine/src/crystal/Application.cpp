#include "cpch.h"

#include "Application.h"
#include "crystal/event/ApplicationEvent.h"
#include "crystal/CLog.h"

#include <glad/glad.h>


namespace Crystal {


	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;	
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(CL_BIND_EVENT(Application::OnEvent));

		m_ImguiLayer = new ImguiLayer();
		PushOverlayer(m_ImguiLayer);

		m_IsRunning = true;

	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClearColor(0, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_ImguiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->ImguiRenderer();
			m_ImguiLayer->End();

			m_Window->OnUpdate();
		}
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(CL_BIND_EVENT(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handle)
				break;
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_IsRunning = false;
		return true;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlayer(Layer* layer)
	{
		m_LayerStack.PushOverLayer(layer);
	}

}