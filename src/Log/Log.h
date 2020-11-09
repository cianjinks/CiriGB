#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Ciri {

	class Log
	{
	public:
		static void InitLogger();
		static inline std::shared_ptr<spdlog::logger>& GetCiriLogger() { return s_CiriLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CiriLogger;
	};
}

#ifdef VX_DEBUG
#define CI_ERROR(...) ::Ciri::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CI_WARN(...) ::Ciri::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CI_TRACE(...) ::Ciri::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CI_CRITICAL(...) ::Ciri::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define CI_INFO(...) ::Ciri::Log::GetCoreLogger()->info(__VA_ARGS__)

#else
#define CI_ERROR
#define CI_WARN
#define CI_TRACE
#define CI_CRITICAL
#define CI_INFO 
#endif