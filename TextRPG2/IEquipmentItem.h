#pragma once

#include "IItem.h"

enum EquipmentType
{
	Helm,
	Armor,
	Weapon,
	TypeEnd
};

class IEquipmentItem abstract : public IItem
{
protected:
	EquipmentType Type	{TypeEnd};
	double AttackIncrease;
	double HealthIncrease;
public:
	IEquipmentItem(EquipmentType type, double attack = 0, double health = 0);
	~IEquipmentItem() override = default;
	void Equip();
	void AddToInventory(shared_ptr<Inventory> inventory, int quantity) override;
	void RemoveToInventory(shared_ptr<Inventory> inventory, int quantity) override;
	double GetAttackIncrease();
	double GetHealthIncrease();
};
