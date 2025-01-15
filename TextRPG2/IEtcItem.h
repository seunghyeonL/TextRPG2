#pragma once

#include "IItem.h"

class IEtcItem abstract : public IItem
{
protected:
	int Gold;

public:
	~IEtcItem() override = default;
	void AddToInventory(shared_ptr<Inventory> inventory, int quantity) override;
	void RemoveToInventory(shared_ptr<Inventory> inventory, int quantity) override;
	int GetGold();
};
