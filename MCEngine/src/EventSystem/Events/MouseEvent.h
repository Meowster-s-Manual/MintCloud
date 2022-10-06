#pragma once
#include "Event.h"

namespace MCEngine {
	class MouseMoveEvent : public Event
	{
	private:
		float mouseX, mouseY;
	public:
		MouseMoveEvent(const float x, const float y)
			: mouseX(x), mouseY(y) {}

		float getX() const { return mouseX; }
		float getY() const { return mouseY; }

		std::string debugString() const override
		{
			std::stringstream stream;
			stream << "MouseMoveEvent: x=" << mouseX << ", y=" << mouseY;
			return stream.str();
		}

		EVENT_GETTER(MouseMove)
		EVENT_FILTER(EventFilterMouse | EventFilterInput)
	};

	class MouseScrollEvent : public Event
	{
	private:
		float scrollX, scrollY;
	public:
		MouseScrollEvent(const float x, const float y)
			: scrollX(x), scrollY(y) {}
		
		float getScrollX() const { return scrollX; }
		float getScrollY() const { return scrollY; }

		std::string debugString() const override
		{
			std::stringstream stream;
			stream << "MouseScrollEvent: x=" << scrollX << ", y=" << scrollY;
			return stream.str();
		}

		EVENT_GETTER(MouseScroll)
		EVENT_FILTER(EventFilterMouse | EventFilterInput)
	};

	class MouseButtonEvent : public Event
	{
	protected:
		// change int to mouse code
		int mouseCode;

		MouseButtonEvent(const int code)
			: mouseCode(code) {}
	public:
		int getMouseCode() const { return mouseCode; }

		EVENT_FILTER(EventFilterMouseButton | EventFilterMouse | EventFilterInput)
	};

	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(const int code)
			: MouseButtonEvent(code) {}

		std::string debugString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonPressEvent: " << mouseCode;
			return stream.str();
		}

		EVENT_GETTER(MouseButtonPress)
	};

	class MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(const int code)
			: MouseButtonEvent(code) {}

		std::string debugString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonReleaseEvent: " << mouseCode;
			return stream.str();
		}

		EVENT_GETTER(MouseButtonRelease)
	};
}