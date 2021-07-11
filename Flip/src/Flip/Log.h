#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Flip {
	class FLIP_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define FP_CORE_FATAL(...)		::Flip::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define FP_CORE_ERROR(...)		::Flip::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FP_CORE_WARN(...)		::Flip::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FP_CORE_INFO(...)		::Flip::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FP_CORE_TRACE(...)		::Flip::Log::GetCoreLogger()->trace(__VA_ARGS__)


//Client log macros
#define FP_FATAL(...)		::Flip::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define FP_ERROR(...)		::Flip::Log::GetClientLogger()->error(__VA_ARGS__)
#define FP_WARN(...)		::Flip::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FP_INFO(...)		::Flip::Log::GetClientLogger()->info(__VA_ARGS__)
#define FP_TRACE(...)		::Flip::Log::GetClientLogger()->trace(__VA_ARGS__)

