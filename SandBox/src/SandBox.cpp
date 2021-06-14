#include <Crystal.h>

class SandBox : public Crystal::Application
{
public:

	SandBox()
	{

	}

	~SandBox()
	{

	}


};



Crystal::Application* Crystal::CreateAppllication()
{
	return new SandBox(); 
}