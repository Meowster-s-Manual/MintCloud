#pragma once
#include "Macros.h"
#include "Event.h"

namespace MCEngine {
	class ENGINE_API EventBus
	{
	public:
		EventBus() {};
		~EventBus() {};



	private:
		std::queue<Event> eventQueue;

	};
}