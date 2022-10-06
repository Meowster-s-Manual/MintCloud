#include "pch.h"
#include "Logger.h"

namespace MCEngine {
	std::shared_ptr<spdlog::logger> Logger::engineLogger;
	std::shared_ptr<spdlog::logger> Logger::gameLogger;

	void Logger::init()
	{
		spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^%l%$] [thread %t] %v");
		engineLogger = spdlog::stdout_color_mt("Mint Engine");

		gameLogger = spdlog::stdout_color_mt("Mint Game");
	}
}
