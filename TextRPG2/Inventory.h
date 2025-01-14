#pragma once
#include "Subject.h"
#include "IItem.h"

class Inventory : public Subject
{
private:
    vector<pair<IItem*, int>> Inven;
    int Gold;
public:
    int GetGold();
    void SetGold(int gold);
    void AddItem(IItem* item);
    void RemoveItem(IItem* item);
};
