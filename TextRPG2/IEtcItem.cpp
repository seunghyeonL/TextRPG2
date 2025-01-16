#include "IEtcItem.h"
#include "Inventory.h"

void IEtcItem::AddToInventory(shared_ptr<Inventory> inventory, int quantity)
{
    inventory->AddToEtc(this, quantity);
}

void IEtcItem::RemoveToInventory(shared_ptr<Inventory> inventory, int quantity)
{
    inventory->RemoveToEtc(this, quantity);
}

int IEtcItem::GetGold()
{
    return Gold;
}
