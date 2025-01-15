#include "IEquipmentItem.h"
#include "Inventory.h"


void IEquipmentItem::AddToInventory(shared_ptr<Inventory> inventory, int quantity)
{
	inventory->AddToEquipment(this);
}

void IEquipmentItem::RemoveToInventory(shared_ptr<Inventory> inventory, int quantity)
{
	inventory->RemoveToEquipment(this);
}

void IEquipmentItem::Equip(Character* character)
{
}
