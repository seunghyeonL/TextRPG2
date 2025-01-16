#pragma once
#include "EventLoop.h"

class IInteractable
{
protected:
	bool IsActive{ true };

public:
	virtual ~IInteractable() = default;
	virtual void Interact() = 0;
	virtual bool GetIsActive() {
		return IsActive;
	};
};
