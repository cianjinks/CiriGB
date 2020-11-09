#include "ciripch.h"
#include "Log.h"

namespace Ciri {

	std::shared_ptr<spdlog::logger> Log::s_CiriLogger;

	void Log::InitLogger()
	{
		spdlog::set_pattern("%^[%T][%n] %v %$");
		s_CiriLogger = spdlog::stdout_color_mt("Ciri");
	}
}