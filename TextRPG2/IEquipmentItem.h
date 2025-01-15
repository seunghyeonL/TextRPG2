#pragma once

#include "IItem.h"

class IEquipmentItem abstract : public IItem
{
public:
	~IEquipmentItem() override = default;
	void AddToInventory(shared_ptr<Inventory> inventory, int quantity) override;
	void RemoveToInventory(shared_ptr<Inventory> inventory, int quantity) override;
	void Equip(Character* character);
};