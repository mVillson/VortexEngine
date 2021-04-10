#pragma once

// --- Core Libraries -------------------------------------
#include <stdio.h>
// --------------------------------------------------------

#ifdef VTX_PLATFORM_WINDOWS
	#ifdef VTX_BUILD_DLL
		#define VORTEX_API __declspec(dllexport)
	#else
		#define VORTEX_API __declspec(dllimport)
	#endif
#else
	#error VortexEngine only supports Winodws!
#endif

