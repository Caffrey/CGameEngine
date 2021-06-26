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

#define BIT(x) (1 << x)