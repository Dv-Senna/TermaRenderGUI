#pragma once



#ifdef TR_STATIC
	#define TR_CORE
#elifdef TR_SHARED
	#ifdef TR_WINDOWS
		#ifdef TR_BUILD_LIB
			#define TR_CORE __declspec(dllexport)
		#else
			#define TR_CORE __declspec(dllimport)
		#endif
	#else
		#define TR_CORE
	#endif
#else
	#error You must define either TR_STATIC or TR_SHARED
#endif
