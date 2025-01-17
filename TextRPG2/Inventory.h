#pragma once
#include "Subject.h"
#include "IEquipmentItem.h"
#include "IConsumptionItem.h"
#include "IEtcItem.h"
#include "IItemStrategy.h"
#include "IItem.h"

class Inventory : public Subject
{
private:
    vector<IEquipmentItem *> EquipmentInven;
    vector<pair<IConsumptionItem *, int>> ConsumptionInven;
    vector<pair<IEtcItem *, int>> EtcInven;
    int Gold;

public:
    Inventory();
    vector<IEquipmentItem *> GetEquipmentInven();
    vector<pair<IConsumptionItem *, int>> GetConsumptionInven();
    vector<pair<IEtcItem *, int>> GetEtcInven();

    vector<IEquipmentItem*>* GetEquipmentInven_Ptr();
    vector<pair<IConsumptionItem*, int>>* GetConsumptionInven_Ptr();
    vector<pair<IEtcItem*, int>>* GetEtcInven_Ptr();

    int GetGold();
    void AddGold(int gold);
    void UseItem(int index);
    void AddDroppedItems(const vector<IItem *> &droppedItems);
    void AddToEquipment(IEquipmentItem *item);
    void AddToConsumption(IConsumptionItem *item, int quantity = 1);
    void AddToEtc(IEtcItem *item, int quantity = 1);
    void RemoveToEquipment(IEquipmentItem *item);
    void RemoveToConsumption(IConsumptionItem *item, int quantity = 1);
    void RemoveToEtc(IEtcItem *item, int quantity = 1);
};
