#pragma once
#include "EventLoop.h"
class IInteractable
{
public:
	virtual ~IInteractable() = default;
	virtual void Interact() = 0;
};

