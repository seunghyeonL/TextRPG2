#include "Inventory.h"

int Inventory::GetGold()
{
    return Gold;
}

void Inventory::SetGold(int gold)
{
    Gold = gold;
}

void Inventory::AddItem(IItem* item)
{
    for (int i = 0; i < Inven.size(); ++i)
    {
        if (Inven[i].first->GetName() == item->GetName())
        {
            Inven[i].second++;
            delete item;
            return;
        }
    }
}

void Inventory::RemoveItem(IItem* item)
{
    for (int i = 0; i < Inven.size(); ++i)
    {
        if (Inven[i].first->GetName() == item->GetName())
        {
            if (Inven[i].second > 1)
            {
                Inven[i].second--;
                return;
            }
            else if (Inven[i].second == 1)
            {
                Inven.erase(remove(Inven.begin(), Inven.end(),
                    Inven[i]), Inven.end());
                return;
            }
        }
    }
}
