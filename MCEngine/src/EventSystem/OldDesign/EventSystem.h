#pragma once
#include "../Macros.h"
#include "Events/Event.h"

#define BUFFER_SIZE 200

namespace MCEngine {
	class ENGINE_API EventSystem
	{
		template<typename T>
		using eventFn = std::function<bool(T&)>;
	private:
		static const Event* buffer[BUFFER_SIZE];
		Event& systemEvent;
		/*Need array/enum/hashmap to hold indiv event classes*/
	public:
		EventSystem(Event& event)
			: systemEvent(event){}

		template<typename T>
		bool eventHandler(eventFn<T> func)
		{
			if (systemEvent.getEventType() == T::getStaticType()) {
				systemEvent.eventHandled = func(*(T*)&systemEvent);
				return true;
			}
			return false;
		}
	};
}
