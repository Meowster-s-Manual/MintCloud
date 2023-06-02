#include "pch.h"
#include "EventTemplate.h"

using namespace MCEngine;

void EventTemplate::update()
{
	Message greeting("EventTemplate says Hi!");
	send(greeting);
}

void EventTemplate::onNotify(Message message)
{
	std::cout << "EventTemplate received: " << message.getEvent() << std::endl;
}