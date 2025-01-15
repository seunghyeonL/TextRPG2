#pragma once

#include "IItem.h"

class IConsumptionItem abstract : public IItem
{
protected:
	bool IsAlreadyUseOne;

public:
	IConsumptionItem();
	~IConsumptionItem() override = default;
	virtual bool Use(class Character* character) = 0;
	void AddToInventory(shared_ptr<Inventory> inventory, int quantity) override;
	void RemoveToInventory(shared_ptr<Inventory> inventory, int quantity) override;
	void SetIsAlreadyUseOne();
};
