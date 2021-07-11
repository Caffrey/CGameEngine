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