#include "Shop.h"
#include "Character.h"
#pragma once

Shop* Shop::GetInstance()
{
	if (Instance == nullptr)
		Instance = new Shop();
	return Instance;
}

void Shop::OnSaleItem()
{
    cout << "현재 판매하고 있는 장비 아이템 목록\n";
    if (GetEquipList().empty())
    {
        cout << "=====================================================================\n";
        cout << "팔고 있는 장비 아이템이 없습니다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
        cout << "현재 가지고 있는 장비 아이템 목록\n\n";
        for (int i = 0; i < GetEquipList().size(); i++)
        {
            cout << i + 1 << ". " << GetEquipList()[i]->GetName() << "\n";
        }
        cout << "=====================================================================\n";
    }
    if (GetConsumptionList().empty())
    {
        cout << "팔고 있는 소비 아이템이 없습니다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
        cout << "현재 판매하고 있는 소비 아이템 목록\n";
        for (int i = 0; i < GetConsumptionList().size(); i++)
        {
            cout << i + 1 << ". " << GetConsumptionList()[i].first->GetName()
                << ": " << GetConsumptionList()[i].second << "개\n";
        }
        cout << "=====================================================================\n";

    }
    if (GetOtherList().empty())
    {
        cout << "팔고 있는 기타 아이템이 없습니다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
     cout << "현재 판매하고 있는 기타 아이템 목록\n";
      for (int i = 0; i < GetConsumptionList().size(); i++)
      {
         cout << i + 1 << ". " << GetConsumptionList()[i].first->GetName()
             << ": " << GetConsumptionList()[i].second << "개\n";
        }
        cout << "=====================================================================\n";
    }
};

vector<IEquipmentItem*> Shop::GetEquipList()
{
	return EquipItem;
}

vector<pair<IConsumptionItem*, int>> Shop::GetConsumptionList()
{
    return ConsumptionItem;
}

vector<pair<IEtcItem*, int>> Shop::GetOtherList()
{
    return OtherItem;
}