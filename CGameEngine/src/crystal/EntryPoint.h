#pragma once

#ifdef CL_PLATFORM_WINDOWS

extern Crystal::Application* Crystal::CreateAppllication();

int main(int argc, char** argv)
{
	Crystal::CLog::Init();

	CORE_CLOG_INFO("Init Log Done")

	auto app = Crystal::CreateAppllication();
	app->Run();
	delete app;
}

#endif 
