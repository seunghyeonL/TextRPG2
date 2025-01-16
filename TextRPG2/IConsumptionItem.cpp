#include "IConsumptionItem.h"
#include "Inventory.h"


IConsumptionItem::IConsumptionItem()
	: IsAlreadyUseOne(false)
{
}

void IConsumptionItem::AddToInventory(shared_ptr<Inventory> inventory, int quantity)
{
	inventory->AddToConsumption(this, quantity);
}

void IConsumptionItem::RemoveToInventory(shared_ptr<Inventory> inventory, int quantity)
{
	inventory->RemoveToConsumption(this, quantity);
}

void IConsumptionItem::SetIsAlreadyUseOne()
{
	IsAlreadyUseOne = false;
}
