#pragma once

#include "Inventory.h"

class IItemStrategy
{
public:
	virtual ~IItemStrategy() = default;
	virtual void Add(Inventory* inventory, IItem* item, int quantity) = 0;
};
