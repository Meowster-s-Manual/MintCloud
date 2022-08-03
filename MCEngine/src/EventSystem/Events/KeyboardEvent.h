#pragma once
#include "Event.h"
#include <sstream>

namespace MCEngine {
	class ENGINE_API KeyboardEvent: public Event 
	{
	protected:
		//TODO: chnage int to keycode
		int keyboardCode;

		KeyboardEvent(const int keyCode)
			: keyboardCode(keyCode) {}

	public:
		//TODO: chnage int to keycode
		int getkeyboardcode() const { return keyboardCode; }
		EVENT_FILTER(EventFilterInput | EventFilterKeyboard)
	};

	class KeyboardPressEvent : public KeyboardEvent 
	{
	private:
		bool isKeyRepeat;
	public:
		KeyboardPressEvent(const int keyCode, bool repeat = false)
			: KeyboardEvent(keyCode), isKeyRepeat(repeat) {}

		bool isRepeated() const { return isKeyRepeat; }

		std::string debugString() const override
		{
			std::stringstream ss;
			ss << "KeyboardPressEvent: " << keyboardCode << " (repeat = " << isKeyRepeat << ")";
			return ss.str();
		}

		EVENT_GETTER(KeyPressed)
	};

	class KeyboardReleaseEvent : public KeyboardEvent
	{
	public:
		KeyboardReleaseEvent(const int keyCode)
			: KeyboardEvent(keyCode) {}

		std::string debugString() const override
		{
			std::stringstream ss;
			ss << "KeyboardReleaseEvent: " << keyboardCode;
			return ss.str();
		}

		EVENT_GETTER(KeyReleased)
	};

	class KeyboardTypedEvent : public KeyboardEvent
	{
	public:
		KeyboardTypedEvent(const int keyCode)
			: KeyboardEvent(keyCode) {}

		std::string debugString() const override
		{
			std::stringstream ss;
			ss << "KeyboardTypedEvent: " << keyboardCode;
			return ss.str();
		}

		EVENT_GETTER(KeyTyped)
	};
}