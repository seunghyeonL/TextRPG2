#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "IEquipmentItem.h"
#include "IConsumptionItem.h"
#include "IEtcItem.h"
#include "IInteractable.h"

class Shop : public IInteractable
{
private:
    static Shop* Instance;
    Shop();
    Shop(const Shop&) = delete;
    Shop& operator=(const Shop&) = delete;
    vector<IEquipmentItem*> EquipItem;
    vector<pair<IConsumptionItem*, int>> ConsumptionItem;
    vector<pair<IEtcItem*, int>> OtherItem;
public:
    static Shop* GetInstance();
    void Init();
    void OnSaleItem();
    vector<IEquipmentItem*> GetEquipList();
    vector<pair<IConsumptionItem*, int>> GetConsumptionList();
    vector<pair<IEtcItem*, int>> GetOtherList();

    // IInteractable을(를) 통해 상속됨
    void Interact() override;
};