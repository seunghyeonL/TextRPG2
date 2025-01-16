#include "EventLoop.h"

IMPLEMENT_SINGLETON(EventLoop)

void EventLoop::AddTask(const function<void()>& Task) {
    Tasks.push(Task);
}

void EventLoop::Run() {
    while (!Tasks.empty()) {
        auto Task = Tasks.front();
        Tasks.pop();
        Task();
    }
}

void EventLoop::Free()
{
    delete this;
}
