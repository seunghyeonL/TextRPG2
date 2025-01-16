#include "IEquipmentItem.h"
#include "Inventory.h"
#include "Character.h"


IEquipmentItem::IEquipmentItem(EquipmentType type, double attack, double health)
{
	Type = type;
	AttackIncrease = attack;
	HealthIncrease = health;
}

void IEquipmentItem::Equip()
{
	Character::GetInstance()->SetEquipmentSlots(this, Type);
}

void IEquipmentItem::AddToInventory(shared_ptr<Inventory> inventory, int quantity)
{
	inventory->AddToEquipment(this);
}

void IEquipmentItem::RemoveToInventory(shared_ptr<Inventory> inventory, int quantity)
{
	inventory->RemoveToEquipment(this);
}

double IEquipmentItem::GetAttackIncrease()
{
	return AttackIncrease;
}

double IEquipmentItem::GetHealthIncrease()
{
	return HealthIncrease;
}
