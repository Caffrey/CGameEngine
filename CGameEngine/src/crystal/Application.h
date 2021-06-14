#pragma once

#include "Core.h"

namespace Crystal {

	class CRYSTAL_API Application
	{
		public:
			Application();
			~Application();
	
	
			virtual void Run();
	};

	Application* CreateAppllication();
}