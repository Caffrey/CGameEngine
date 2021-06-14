#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"


namespace Crystal
{
	class CRYSTAL_API CLog
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

#define CORE_CLOG_INFO(...) ::Crystal::CLog::GetCoreLogger()->info(__VA_ARGS__);
#define CORE_CLOG_WARN(...) ::Crystal::CLog::GetCoreLogger()->warn(__VA_ARGS__);
#define CORE_CLOG_ERROR(...) ::Crystal::CLog::GetCoreLogger()->error(__VA_ARGS__);