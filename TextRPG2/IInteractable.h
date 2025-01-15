#pragma once
#include "IMapObject.h"

class IInteractable: public IMapObject
{
public:
	virtual ~IInteractable() = default;
	virtual void Interact() = 0;
};

