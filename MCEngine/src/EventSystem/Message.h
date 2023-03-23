#pragma once
#include "pch.h"
#include "Macros.h"

namespace MCEngine {
    class ENGINE_API Message
    {
    public:
        Message(const std::string event)
        {
            messageEvent = event;
        }

        std::string getEvent()
        {
            return messageEvent;
        }
    private:
        std::string messageEvent;
    };
}