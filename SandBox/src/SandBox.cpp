#include <Crystal.h>



class ExampleLayer : public Crystal::Layer
{
public:
	ExampleLayer() :Layer("Example Layer")
	{
	
	
	};
	~ExampleLayer() {};

	virtual void OnEvent(Crystal::Event& event) override
	{
		if (event.GetEventType() == Crystal::EventType::KeyPressed)
		{
			Crystal::KeyPressedEvent e = (Crystal::KeyPressedEvent&)event;
			CORE_CLOG_INFO("Key{0}", e.GetKeyCode());
		}
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