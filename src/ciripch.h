#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <stdint.h>
#include <limits.h> 
#include <assert.h>

#include "Util/BitUtils.h"
#include "Log/Log.h"

#ifdef CI_DEBUG
	#if defined(CI_PLATFORM_WINDOWS)
		#define CI_DEBUG_BREAK() __debugbreak()
	#elif defined(CI_PLATFORM_LINUX)
		#include <signal.h>
		#define CI_DEBUG_BREAK() raise(SIGTRAP)
	#else
		#error "Platform does not support debugging"
	#endif 
#else
	#define CI_DEBUG_BREAK()
#endif

#define CI_ASSERT(x, ...) { if(!(x)) { CI_ERROR("Assertion Failed: {0}", __VA_ARGS__); CI_DEBUG_BREAK(); } }