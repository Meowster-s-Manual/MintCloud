#pragma once
#include "pch.h"
#include "Macros.h"
#include "Message.h"
#include "EventBus.h"

namespace MCEngine {
    class ENGINE_API Event
    {
    public:
        Event(EventBus* eventBus)
        {
            this->eventBus = eventBus;
            this->eventBus->addEventListeners(this->getNotifyFunc());
        }

        virtual void update() {}
    protected:
        EventBus* eventBus;

        std::function<void(Message)> getNotifyFunc()
        {
            auto messageListener = [=](Message message) -> void {
                this->onNotify(message);
            };
            return messageListener;
        }

        void send(Message message)
        {
            eventBus->pushToEventQueue(message);
        }

        virtual void onNotify(Message message)
        {
            // Do something here. Your choice. But you could do this.
            // std::cout << "Siopao! Siopao! Siopao! (Someone forgot to implement onNotify().)" << std::endl;
        }
    };
}