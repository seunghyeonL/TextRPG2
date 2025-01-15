#include "Inventory.h"
#include "Character.h"

Inventory::Inventory()
    : Gold(0)
{

}

vector<IEquipmentItem*> Inventory::GetEquipmentInven()
{
    return EquipmentInven;
}

vector<pair<IConsumptionItem*, int>> Inventory::GetConsumptionInven()
{
    return ConsumptionInven;
}

vector<pair<IEtcItem*, int>> Inventory::GetEtcInven()
{
    return EtcInven;
}

int Inventory::GetGold()
{
    return Gold;
}

void Inventory::AddGold(int gold)
{
    Gold += gold;
}

void Inventory::UseItem(int index)
{
    if (index >= 0 && index < ConsumptionInven.size())
    {
        cout << ConsumptionInven[index].first->GetName() << "을(를) 사용합니다.\n";
        bool IsCanUse = ConsumptionInven[index].first->Use(Character::GetInstance());
        if(IsCanUse)
            RemoveToConsumption(ConsumptionInven[index].first);
    }
}

void Inventory::AddDroppedItems(const vector<IItem*>& droppedItems)
{
    for (IItem* item : droppedItems)
    {
        if (auto* equipmentItem = dynamic_cast<IEquipmentItem*>(item)) 
        {
            AddToEquipment(equipmentItem);
        }
        else if (auto* consumptionItem = dynamic_cast<IConsumptionItem*>(item)) 
        {
            AddToConsumption(consumptionItem); 
        }
        else if (auto* etcItem = dynamic_cast<IEtcItem*>(item)) 
        {
            AddToEtc(etcItem);
        }
    }
}

void Inventory::AddToEquipment(IEquipmentItem* item)
{
    if (EquipmentInven.empty())
        EquipmentInven.push_back(item);

    else
    {
        for (int i = 0; i < EquipmentInven.size(); ++i)
        {
            if (EquipmentInven[i]->GetName() == item->GetName())
            {
                cout << "동일한 아이템을 갖고 있습니다." << endl;
                return;
            }
        }
        EquipmentInven.push_back(item);
    }
}

void Inventory::AddToConsumption(IConsumptionItem* item, int quantity)
{
    if (ConsumptionInven.empty())
        ConsumptionInven.push_back(make_pair(item, quantity));

    else
    {
        for (int i = 0; i < ConsumptionInven.size(); ++i)
        {
            if (ConsumptionInven[i].first->GetName() == item->GetName())
            {
                ConsumptionInven[i].second += quantity;
                delete item;
                return;
            }
        }
        ConsumptionInven.push_back(make_pair(item, quantity));
    }
}

void Inventory::AddToEtc(IEtcItem* item, int quantity)
{
    if (EtcInven.empty())
        EtcInven.push_back(make_pair(item, quantity));

    else
    {
        for (int i = 0; i < EtcInven.size(); ++i)
        {
            if (EtcInven[i].first->GetName() == item->GetName())
            {
                EtcInven[i].second += quantity;
                delete item;
                return;
            }
        }
        EtcInven.push_back(make_pair(item, quantity));
    }
}

void Inventory::RemoveToEquipment(IEquipmentItem* item)
{
    for (int i = 0; i < EquipmentInven.size(); ++i)
    {
        if (EquipmentInven[i]->GetName() == item->GetName())
            EquipmentInven.erase(remove(EquipmentInven.begin(), EquipmentInven.end(),
                EquipmentInven[i]), EquipmentInven.end());
    }
}

void Inventory::RemoveToConsumption(IConsumptionItem* item, int quantity)
{
    for (int i = 0; i < ConsumptionInven.size(); ++i)
    {
        if (ConsumptionInven[i].first->GetName() == item->GetName())
        {
            if (ConsumptionInven[i].second > 1)
            {
                ConsumptionInven[i].second -= quantity;
                return;
            }
            else if (ConsumptionInven[i].second == 1)
            {
                ConsumptionInven.erase(remove(ConsumptionInven.begin(), ConsumptionInven.end(),
                    ConsumptionInven[i]), ConsumptionInven.end());
                return;
            }
        }
    }
}

void Inventory::RemoveToEtc(IEtcItem* item, int quantity)
{
    for (int i = 0; i < EtcInven.size(); ++i)
    {
        if (EtcInven[i].first->GetName() == item->GetName())
        {
            if (EtcInven[i].second > 1)
            {
                EtcInven[i].second -= quantity;
                return;
            }
            else if (EtcInven[i].second == 1)
            {
                EtcInven.erase(remove(EtcInven.begin(), EtcInven.end(),
                    EtcInven[i]), EtcInven.end());
                return;
            }
        }
    }
}
