#pragma once
#include "../Message.h"
#include "../EventBus.h"
#include "../Event.h"

namespace MCEngine {
    // Event Template.
    class ENGINE_API EventTemplate : public Event
    {
    public:
        EventTemplate(EventBus* eventBus) : Event(eventBus) {}

        void update();
    private:
        void onNotify(Message message);
    };
}