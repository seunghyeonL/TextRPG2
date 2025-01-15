#pragma once
#include "Client_Defines.h"

class IMapObject
{
public:
	virtual ~IMapObject() = default;
	virtual void Interact() {};
};

