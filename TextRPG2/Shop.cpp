#include "Shop.h"
#include "Character.h"
#include "LeatherShoes.h"
#include "HealthPotion.h"
#include "TrollTooth.h"
#include "ShabbyHelm.h"
#include "LiquidMass.h"
#include "BoneHelm.h"
#include "AttackBoost.h"

#include "CanineMass.h"
#include "GreenLeatherHelm.h"
#include "GoblinKnife.h"
#pragma once

Shop* Shop::Instance = nullptr;

Shop::Shop()
{
}

Shop* Shop::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new Shop();
    }
    return Instance;
}

void Shop::Init()
{
    EquipItem.push_back(new LeatherShoes());
    EquipItem.push_back(new ShabbyHelm());
    EquipItem.push_back(new BoneHelm());
    EquipItem.push_back(new GreenLeatherHelm());

    ConsumptionItem.push_back(make_pair(new HealthPotion(),20));
    ConsumptionItem.push_back(make_pair(new AttackBoost(), 20));
    
    OtherItem.push_back(make_pair(new TrollTooth(), 20));
    OtherItem.push_back(make_pair(new LiquidMass(), 20));
    OtherItem.push_back(make_pair(new CanineMass(), 20));
    OtherItem.push_back(make_pair(new GoblinKnife(), 20));

}

void Shop::OnSaleItem()
{
    cout << "현재 판매하고 있는 장비 아이템 목록\n";
    if (EquipItem.empty())
    {
        cout << "=====================================================================\n";
        cout << "팔고 있는 장비 아이템이 없습니다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
        cout << "현재 가지고 있는 장비 아이템 목록\n\n";
        for (int i = 0; i < EquipItem.size(); i++)
        {
            cout << i + 1 << ". " << EquipItem[i]->GetName() << "\n";
        }
        cout << "=====================================================================\n";
    }
    if (ConsumptionItem.empty())
    {
        cout << "팔고 있는 소비 아이템이 없습니다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
        cout << "현재 판매하고 있는 소비 아이템 목록\n";
        for (int i = 0; i < ConsumptionItem.size(); i++)
        {
            cout << i + 1 << ". " << ConsumptionItem[i].first->GetName()
                << ": " << ConsumptionItem[i].second << "개\n";
        }
        cout << "=====================================================================\n";

    }
    if (OtherItem.empty())
    {
        cout << "팔고 있는 기타 아이템이 없습니다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
        cout << "현재 판매하고 있는 기타 아이템 목록\n";
        for (int i = 0; i < OtherItem.size(); i++)
        {
            cout << i + 1 << ". " << OtherItem[i].first->GetName()
                << ": " << OtherItem[i].second << "개\n";
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

vector<IEquipmentItem*>* Shop::GetEquipList_Ptr()
{
    return &EquipItem;
}

vector<pair<IConsumptionItem*, int>>* Shop::GetConsumptionList_Ptr()
{
    return &ConsumptionItem;
}

vector<pair<IEtcItem*, int>>* Shop::GetOtherList_Ptr()
{
    return &OtherItem;
}

void Shop::Interact()
{

}
