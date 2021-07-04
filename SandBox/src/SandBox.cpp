#include <Crystal.h>

class ExampleLayer : public Crystal::Layer
{
public:
	ExampleLayer() :Layer("Example")
	{

	}

	void OnUpdate() override
	{
		CORE_CLOG_INFO("Example Layer update");
	}

	void OnEvent(Crystal::Event& event) override
	{
		CORE_CLOG_WARN("Example Layer Event {0}", event);
	}


};



class SandBox : public Crystal::Application
{
public:

	SandBox()
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox()
	{

	}


};

Crystal::Application* Crystal::CreateAppllication()
{
	return new SandBox(); 
}