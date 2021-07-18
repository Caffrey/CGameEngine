#include "cpch.h"

#include "Application.h"
#include "crystal/event/ApplicationEvent.h"
#include "crystal/CLog.h"

#include "crystal/Renderer/Buffer.h"

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

		//vertex array
		glGenVertexArrays(1, &m_vertexArray);
		glBindVertexArray(m_vertexArray);


		float vetrics[9] = {
			-.5f , -.5f , .0f,
			.5f , -.5f , .0f,
			.0f,.5f,.0f,
		};


		m_VertexBuffer.reset(VertexBuffer::Create(vetrics,sizeof(vetrics)));
		

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),nullptr);


		unsigned int indices[3] = { 0,1,2 };
		m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices)));
		
		std::string vertexSource = R"(
			#version 330 core
			layout(location = 0) in vec3 a_Position;
			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position.xyz,1);
			}
		)";

		std::string pixelSource= R"(
			#version 330 core
			layout(location = 0) out vec4 color;
			in vec3 v_Position;			
			void main()
			{
				color = vec4(v_Position.xyz, 1);
			}
		)";


		m_Shader.reset(new Shader(vertexSource,pixelSource));





		//vertex buffer
		//index buffer
		//shader

	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClearColor(0.3, .3, 0.3, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_VertexBuffer->Bind();
			glBindVertexArray(m_vertexArray);
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->Count(), GL_UNSIGNED_INT, nullptr); 

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