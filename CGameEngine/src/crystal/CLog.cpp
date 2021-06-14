#include "CLog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Crystal 
{
	std::shared_ptr<spdlog::logger> CLog::s_CoreLogger;
	std::shared_ptr<spdlog::logger> CLog::s_ClientLogger;

	void CLog::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("CRYSTAL");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_CoreLogger = spdlog::stdout_color_mt("APP");
		s_CoreLogger->set_level(spdlog::level::trace);

	}

}