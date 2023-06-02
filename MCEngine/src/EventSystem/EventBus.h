#pragma once
#include "pch.h"
#include "Macros.h"
#include "Message.h"

namespace MCEngine {
    class ENGINE_API EventBus
    {
    public:
        EventBus() {};
        ~EventBus() {};

        // TODO create updateAll() function to group all the updates to a single update function for game loop

        void addEventListeners(std::function<void(Message)> messageReceiver)
        {
            eventRecipients.push_back(messageReceiver);
        }

        void pushToEventQueue(Message message)
        {
            eventQueue.push(message);
        }

        void notify()
        {
            while (!eventQueue.empty()) {
                for (auto iter = eventRecipients.begin(); iter != eventRecipients.end(); iter++) {
                    (*iter)(eventQueue.front());
                }

                eventQueue.pop();
            }
        }

    private:
        std::vector<std::function<void(Message)>> eventRecipients;
        std::queue<Message> eventQueue;
    };

}