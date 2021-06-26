#include "cpch.h"

#include "Application.h"

#include "crystal/event/ApplicationEvent.h"
#include "crystal/CLog.h"


namespace Crystal{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);

		CORE_CLOG_INFO(e);
		while (true);
	}


}