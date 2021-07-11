#include <Crystal.h>




class SandBox : public Crystal::Application
{
public:

	SandBox()
	{
		PushLayer(new Crystal::ImguiLayer());
	}

	~SandBox()
	{

	}


};

Crystal::Application* Crystal::CreateAppllication()
{
	return new SandBox(); 
}