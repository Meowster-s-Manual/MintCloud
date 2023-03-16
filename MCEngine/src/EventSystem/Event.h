#pragma once
#include "Macros.h"

namespace MCEngine {
	class ENGINE_API Event
	{
	public:
		Event() {};
		~Event() {};
		std::string GetEvent();
		
	private:
		std::string event;

	};
}