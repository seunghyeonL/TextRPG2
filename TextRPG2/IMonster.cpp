#include "IMonster.h"

IMonster::IMonster()
{
}

void IMonster::Free()
{
}

// void IMonster::interact() {
//	auto gameManager = GameManager::Get_Instance();
//
//	gameManager->Battle(this);
// }

// 아이템 드랍 로직
vector<IItem *> IMonster::DropRandomItem()
{
    vector<IItem *> DroppedItems;
    unordered_set<IEquipmentItem *> DroppedEquipment;
    unordered_set<IConsumptionItem *> DroppedConsumables;
    unordered_set<IEtcItem *> DroppedOther;

    // 드랍할 아이템 개수 무작위 결정 (1 ~ 2)
    int itemCount = rand() % 2 + 1;

    while (DroppedItems.size() < itemCount)
    {
        DropTable RandomItemType = static_cast<DropTable>(rand() % 3);

        switch (RandomItemType)
        {
        case DropTable::장비:
        {
            // 중복된 장비가 아니면 드랍
            IEquipmentItem *item = EquipmentItems[rand() % EquipmentItems.size()];
            if (DroppedEquipment.find(item) == DroppedEquipment.end())
            {
                DroppedItems.push_back(item);
                DroppedEquipment.insert(item);
            }
        }
        break;

        case DropTable::소비:
        {
            // 중복된 소비 아이템이 아니면 드랍
            IConsumptionItem *item = ConsumableItems[rand() % ConsumableItems.size()];
            if (DroppedConsumables.find(item) == DroppedConsumables.end())
            {
                DroppedItems.push_back(item);
                DroppedConsumables.insert(item);
            }
        }
        break;

        case DropTable::기타:
        {
            // 중복된 기타 아이템이 아니면 드랍
            IEtcItem *item = OtherItems[rand() % OtherItems.size()];
            if (DroppedOther.find(item) == DroppedOther.end())
            {
                DroppedItems.push_back(item);
                DroppedOther.insert(item);
            }
        }
        break;
        }
    }

    // 드랍된 아이템 출력 - 임시
    cout << "드랍된 아이템들: ";
    for (const auto &item : DroppedItems)
    {
        cout << item->GetName() << " ";
    }
    cout << endl;
    return DroppedItems;
}
void IMonster::Interact()
{
    auto pGameManager = GameManager::Get_Instance();

    pGameManager->Battle(this);
    system("cls");
}
