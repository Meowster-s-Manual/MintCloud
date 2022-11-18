#pragma once
#include "../Macros.h"

#define MINT_LOGGER "MintLogger"

namespace MCEngine {
	template class ENGINE_API std::shared_ptr<spdlog::logger>;

	class ENGINE_API Logger 
	{
	public:
		static void init();

		static std::shared_ptr<spdlog::logger>& getEngineLogger() { return engineLogger; }
		static std::shared_ptr<spdlog::logger>& getGameLogger() { return gameLogger; }
	private:
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> gameLogger;
	};
}


// TODO: setup relaese and debugg tags
#define DEBUG 1
#ifdef DEBUG
	#define MINT_ENGINE_TRACE(...)    ::MCEngine::Logger::getEngineLogger()->trace(__VA_ARGS__)
	#define MINT_ENGINE_DEBUG(...)    ::MCEngine::Logger::getEngineLogger()->debug(__VA_ARGS__)
	#define MINT_ENGINE_INFO(...)     ::MCEngine::Logger::getEngineLogger()->info(__VA_ARGS__)
	#define MINT_ENGINE_WARN(...)     ::MCEngine::Logger::getEngineLogger()->warn(__VA_ARGS__)
	#define MINT_ENGINE_ERROR(...)    ::MCEngine::Logger::getEngineLogger()->error(__VA_ARGS__)
	#define MINT_ENGINE_CRITICAL(...) ::MCEngine::Logger::getEngineLogger()->critical(__VA_ARGS__)

	#define MINT_TRACE(...)           ::MCEngine::Logger::getGameLogger()->trace(__VA_ARGS__)
	#define MINT_DEBUG(...)           ::MCEngine::Logger::getGameLogger()->debug(__VA_ARGS__)
	#define MINT_INFO(...)            ::MCEngine::Logger::getGameLogger()->info(__VA_ARGS__)
	#define MINT_WARN(...)            ::MCEngine::Logger::getGameLogger()->warn(__VA_ARGS__)
	#define MINT_ERROR(...)           ::MCEngine::Logger::getGameLogger()->error(__VA_ARGS__)
	#define MINT_CRITICAL(...)		  ::MCEngine::Logger::getGameLogger()->critical(__VA_ARGS__)
#else
	#define MINT_ENGINE_TRACE(...)	  (void)0
	#define MINT_ENGINE_DEBUG(...)	  (void)0
	#define MINT_ENGINE_INFO(...)	  (void)0
	#define MINT_ENGINE_WARN(...)	  (void)0
	#define MINT_ENGINE_ERROR(...)	  (void)0
	#define MINT_ENGINE_CRITICAL(...) (void)0

	#define MINT_TRACE(...)			  (void)0
	#define MINT_DEBUG(...)			  (void)0
	#define MINT_INFO(...)			  (void)0
	#define MINT_WARN(...)			  (void)0
	#define MINT_ERROR(...)			  (void)0
	#define MINT_CRITICAL(...)		  (void)0
#endif