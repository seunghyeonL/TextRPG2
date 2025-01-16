#pragma once
#include "Client_Defines.h"
#include <iostream>
#include <queue>
#include <functional>
#include <memory>

class EventLoop {
	DECLARE_SINGLETON(EventLoop)
private:
	EventLoop() {};
	virtual ~EventLoop() = default;
	queue<function<void()>> Tasks; // Task function queue.

public:
	void AddTask(const function<void()>& Task); 
	void Run(); // Pop and run every tasks in task queue. 
	void Free();
};