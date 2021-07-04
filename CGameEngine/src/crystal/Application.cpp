#include "cpch.h"

#include "Application.h"
#include "crystal/event/ApplicationEvent.h"
#include "crystal/CLog.h"

#include <glad/glad.h>


namespace Crystal {

#define BIND_EVENT(x) std::bind(&Application::x, this, std::placeholders::_1)


	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT(OnEvent));
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
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handle)
				break;
		}

	}

	void Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_IsRunning = false;
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