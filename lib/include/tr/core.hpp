#pragma once



#ifdef TR_STATIC
	#define TR_CORE
#elifdef TR_SHARED
	#ifdef TR_WINDOWS
		#ifdef TR_BUILD_LIB
			#define SE_CORE __declspec(dllexport)
		#else
			#define SE_CORE __declspec(dllimport)
		#endif
	#else
		#define SE_CORE
	#endif
#else
	#error You must define either TR_STATIC or TR_SHARED
#endif
