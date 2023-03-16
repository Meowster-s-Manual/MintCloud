//#include <MCEngine.h>
//
//int main()
//{
//	MCEngine::EngineApp* engine = new MCEngine::EngineApp();
//
//	engine->start();
//
//}

#include <iostream>
#include <functional>
#include <queue>
#include <vector>

class Message
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

class EventBus
{
public:
    EventBus() {};
    ~EventBus() {};

    void addEventRecipient(std::function<void(Message)> messageReceiver)
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

class Event
{
public:
    Event(EventBus* eventBus)
    {
        this->eventBus = eventBus;
        this->eventBus->addEventRecipient(this->getNotifyFunc());
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

// This class will receive a message from ComponentB.
class EventA : public Event
{
public:
    EventA(EventBus* eventBus) : Event(eventBus) {}

    void update()
    {
        Message greeting("Bye!");
        send(greeting);
    }

private:
    void onNotify(Message message)
    {
        std::cout << "A received: " << message.getEvent() << std::endl;
    }
};

// This class will send a message to ComponentA.
class EventB : public Event
{
public:
    EventB(EventBus* eventBus) : Event(eventBus) {}

    void update()
    {
        Message greeting("Hi!");
        send(greeting);
    }

private:
    void onNotify(Message message)
    {
        std::cout << "B received: " << message.getEvent() << std::endl;
    }
};


int main()
{
    EventBus eventBus;
    EventA compA(&eventBus);
    EventB compB(&eventBus);

    // This is supposed to act like a game loop.
    for (int ctr = 0; ctr < 50; ctr++) {
        compA.update();
        compB.update();
        eventBus.notify();
    }

    return 0;
}