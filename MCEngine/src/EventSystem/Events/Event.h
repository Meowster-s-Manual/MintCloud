#pragma once
#include "../../Core.h"

#include <string>

// forward declaration
class EventSystem;

#define EVENT_GETTER(type)\
	static EventType getStaticType() { return EventType::##type; }\
	virtual EventType getEventType() const override { return getStaticType(); }\
	virtual const char* getEventName() const override { return #type; }

#define EVENT_SIEVE(filter) virtual int getEventFilters() const override { return filter; }

namespace MCEngine {
	enum class EventType
	{
		None = 0,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventFilter
	{
		None = 0,
		EventFilterInput           = BIT(0),
		EventFilterKeyboard        = BIT(1),
		EventFilterMouse           = BIT(2),
		EventFilterMouseButton     = BIT(3)
	};

	class ENGINE_API Event {
		friend class EventSystem;
	protected:
		bool eventHandled = false;
	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getEventName() const = 0;
		virtual int getEventFilters() const = 0;
		virtual std::string debugString() const { return getEventName(); }
		bool isInFilter(EventFilter filter);
	};

	inline bool Event::isInFilter(EventFilter filter) {
		return Event::getEventFilters() & filter;
	};
}