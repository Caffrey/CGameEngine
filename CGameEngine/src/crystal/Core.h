#pragma once


#ifdef CL_PLATFORM_WINDOWS
	#ifdef CRYSTAL_BUILD_DLL
		#define  CRYSTAL_API _declspec(dllexport)
			#else
		#define  CRYSTAL_API _declspec(dllimport)
	#endif
#else

	#error Crystal only suport window !

#endif

#ifdef CL_ENABLE_ASSERTS
	#define CL_ASSERT(x,...) {if(!(x)) {CORE_CLOG_ERROR("Asserts Failed :{0}",__VA_ARGS__); __debugbreak(); }}
	#define CL_CORE_ASSERT(x,...) {if(!(x)) {CORE_CLOG_ERROR("Asserts Failed :{0}",__VA_ARGS__); __debugbreak(); }}

#else
	#define CL_ASSERT(x,...)
	#define CL_CORE_ASSERT(x,...)

#endif

#define BIT(x) (1 << x)

#define CL_BIND_EVENT(x) std::bind(&x, this, std::placeholders::_1)

//----------------------------Platform Spcitfy Marco

#ifdef CRYSTAL_SYSTEM_API_CRYSTAL

	#define CRYSTAL_INPUT_API_GLFW 1

#else CRYSTAL_SYSTEM_API_WINDOWS

	#define CRYSTAL_INPUT_API_WINDOWS 1
#endif

//----------------------------Platform Spcitfy Marco