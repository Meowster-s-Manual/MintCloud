#pragma once
#include "../Core.h"

#define BUFFER_SIZE 200

namespace MCEngine {
	class EventSystem
	{
	private:
		void* buffer[BUFFER_SIZE];
		/*Need array/enum/hashmap to hold indiv event classes*/
	public:
		EventSystem();
		~EventSystem();
		int addEvent(void *Event);
		int removeEvent(void *Event);
		int eventHandler(void *Event);
	};
}
