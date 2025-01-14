#pragma once
#include "Subject.h"
#include "IItem.h"


class Inventory : public Subject
{
private:
    vector<pair<IItem*, int>> Inven;
    int Gold;

public:
    Inventory();
    vector<pair<IItem*, int>> GetInventory();
    int GetGold();
    void AddGold(int gold);
    void AddItem(IItem* item);
    void RemoveItem(IItem* item);
    void UseItem(int index);
};
