#pragma once

#ifdef CL_PLATFORM_WINDOWS

extern Crystal::Application* Crystal::CreateAppllication();

int main(int argc, char** argv)
{
	auto app = Crystal::CreateAppllication();
	app->Run();
	delete app;
}



#endif 
