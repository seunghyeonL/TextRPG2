#include "Inventory.h"
#include "Character.h"

Inventory::Inventory()
    : Gold(0)
{

}

vector<pair<IItem*, int>> Inventory::GetInventory()
{
    return Inven;
}

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
    if (Inven.empty())
        Inven.push_back(make_pair(item, 1));

    else
    {
        for (int i = 0; i < Inven.size(); ++i)
        {
            if (Inven[i].first->GetName() == item->GetName())
            {
                Inven[i].second++;
                delete item;
                return;
            }
            else
            {
                Inven.push_back(make_pair(item, 1));
                return;
            }
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

void Inventory::UseItem(int index)
{
    if (index >= 0 && index < Inven.size())
    {
        cout << Inven[index].first->GetName() << "을(를) 사용합니다.\n";
        Inven[index].first->Use(Character::GetInstance());
        RemoveItem(Inven[index].first);
    }
}
