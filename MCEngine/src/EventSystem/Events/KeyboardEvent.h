#pragma once
#include "Event.h"

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
			std::stringstream stream;
			stream << "KeyboardPressEvent: " << keyboardCode << " (repeat = " << isKeyRepeat << ")";
			return stream.str();
		}

		EVENT_GETTER(KeyPress)
	};

	class KeyboardReleaseEvent : public KeyboardEvent
	{
	public:
		KeyboardReleaseEvent(const int keyCode)
			: KeyboardEvent(keyCode) {}

		std::string debugString() const override
		{
			std::stringstream stream;
			stream << "KeyboardReleaseEvent: " << keyboardCode;
			return stream.str();
		}

		EVENT_GETTER(KeyRelease)
	};

	class KeyboardTypeEvent : public KeyboardEvent
	{
	public:
		KeyboardTypeEvent(const int keyCode)
			: KeyboardEvent(keyCode) {}

		std::string debugString() const override
		{
			std::stringstream stream;
			stream << "KeyboardTypedEvent: " << keyboardCode;
			return stream.str();
		}

		EVENT_GETTER(KeyType)
	};
}