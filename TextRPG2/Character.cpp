#include <iostream>
#include <string>
#include <sstream>
#include "GameManager.h"
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Character *Character::Instance = nullptr;

Character::Character(string name)
    : Name(name), Level(1), Health(200),
      MaxHealth(MAX_HEALTH), MaxExperience(100), Attack(30), Experience(0), Inven(make_shared<Inventory>()),
      pGameManager{GameManager::Get_Instance()}
{
    HealthPotion *potion = new HealthPotion();
    AttackBoost *AB = new AttackBoost();
    potion->AddToInventory(Inven, 10);
    AB->AddToInventory(Inven, 5);
}

Character *Character::GetInstance(string name)
{
    if (Instance == nullptr)
        Instance = new Character(name);

    return Instance;
}

string Character::GetName()
{
    return Name;
}

int Character::GetLevel()
{
    return Level;
}

void Character::SetLevel(int level)
{
    Level = level;
}

double Character::GetHealth()
{
    return Health;
}

void Character::SetHealth(double health)
{
    if (health >= MaxHealth)
    {
        Health = MaxHealth;
    }
    else if (health > 0 && health < MaxHealth)
    {
        Health = health;
    }
    else if (Health <= 0)
    {
        Health = 0;
    }
}

double Character::GetAttack()
{
    return Attack;
}

void Character::GetDamage(double attack)
{
    Health -= attack;
    if (Health <= 0)
    {
        Health = 0;
    }
}

void Character::SetAttack(double attack)
{
    Attack = attack;
}

void Character::TakeDamage(double damage)
{
    Health -= damage;
    if (Health < 0)
        Health = 0;
}

double Character::GetExperience()
{
    return Experience;
}

double Character::GetMaxExperience()
{
    return MaxExperience;
}

double Character::GetGold()
{
    return Inven->GetGold();
}

void Character::DisplayStatus()
{
    cout << "\n현재 레벨 : " << Level << "레벨 " << Experience / MaxExperience * 100 << "% 경험치\n";
    cout << "현재 체력 : " << Health << " / " << MaxHealth << " (" << Health / MaxHealth * 100 << "%)\n";
    cout << "현재 공격력 : " << Attack << "\n";
    cout << "현재 보유 골드 : " << Inven->GetGold() << "\n\n";
}

void Character::DisplayInventory()
{
    if (Inven->GetEquipmentInven().empty())
    {
        cout << "=====================================================================\n";
        cout << "장비창은 비어있다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
        cout << "현재 가지고 있는 장비 아이템 목록\n\n";
        for (int i = 0; i < Inven->GetEquipmentInven().size(); i++)
        {
            cout << i + 1 << ". " << Inven->GetEquipmentInven()[i]->GetName() << "\n";
        }
        cout << "=====================================================================\n";
    }
    if (Inven->GetConsumptionInven().empty())
    {
        cout << "소비창은 비어있다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
        cout << "현재 가지고 있는 소비 아이템 목록\n\n";
        for (int i = 0; i < Inven->GetConsumptionInven().size(); i++)
        {
            cout << i + 1 << ". " << Inven->GetConsumptionInven()[i].first->GetName()
                << ": " << Inven->GetConsumptionInven()[i].second << "개\n";
        }
        cout << "=====================================================================\n";
            
    }
    if (Inven->GetEtcInven().empty())
    {
        cout << "기타창은 비어있다.\n";
        cout << "=====================================================================\n";
    }
    else
    {
        cout << "현재 가지고 있는 기타 아이템 목록\n";
        for (int i = 0; i < Inven->GetEtcInven().size(); i++)
        {
            cout << i + 1 << ". " << Inven->GetEtcInven()[i].first->GetName()
                << ": " << Inven->GetEtcInven()[i].second << "개\n";
        }
        cout << "=====================================================================\n";
    }
}

void Character::LevelUp()
{
    if (Experience >= MaxExperience && Level != MaxLevel)
    {
        Experience = 0;
        Level++;
        MaxHealth += Level * 20;
        Health = MaxHealth;
        Attack += Level * 5;
        MaxExperience += 10;
        cout << "\nLevel up! 현재 레벨은 " << Level << "입니다.\n";
    }
    if (Level == MaxLevel)
    {
        cout << "\n현재 최대 레벨입니다.\n";
    }
}

void Character::AddExperience(double amount) { Experience += amount; }

shared_ptr<Inventory> Character::GetInventory()
{
    return Inven;
}

void Character::BuyItem()
{
    string name;
    int choice;
    /*  해야할 목록
                상점아이템 나열
                번호 입력
                해당 번호의 아이템을 구매
                아이템 구매가만큼 플레이어 인벤토리의 골드 감소
                상점 아이템의 해당 아이템 개수 감소
                플레이어 인벤토리 내 해당 아이템 개수 증가*/
    cout << "\n구매하고 싶은 아이템 번호를 써주세요.\n";
    cin >> choice;
    //cout << shop->OnSaleItem() << " 아이템을 구매하시겠습니까?\n";
    cout << "1. 네     2. 아니요\n";
    cin >> choice;
    while (true)
    {
        if (choice == 1)
        {
            // 구매
            // shop->BuyItem(index, inventory);
            break;
        }
        else if (choice == 2)
        {

        }
        break;
    };
};

bool Character::SellItem()
{
    Character* Player = Character::GetInstance();
    vector<IEquipmentItem*> EquipmentInven = Player->GetInventory()->GetEquipmentInven();
    vector<pair<IConsumptionItem*, int>> ConsumptionInven = Player->GetInventory()->GetConsumptionInven();
    vector<pair<IEtcItem*, int>> EtcInven = Player->GetInventory()->GetEtcInven();

    string name;
    int choice;

    while (true)
    {
        cout << "\n판매하고 싶은 아이템의 이름을 써주세요.\n";
        cin >> name;
        cout << "\n" << name << " 아이템을 판매하시겠습니까?\n";
        cout << "1. 네     2. 아니요\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n판매할 수량을 입력해주세요.\n";
            int Quantity;
            cin >> Quantity;
            if (Quantity < 0 || Quantity > EquipmentInven.size() || Quantity > ConsumptionInven.size() || Quantity > EtcInven.size())
            {
                cout << "\n잘못된 입력입니다.\n";
            }
            else
            {
                if (Quantity == 1)
                {
                    for (int i = 0; i < EquipmentInven.size(); ++i)
                    {
                        if (EquipmentInven[i]->GetName() == name)
                        {
                            EquipmentInven.erase(remove(EquipmentInven.begin(), EquipmentInven.end(),
                                EquipmentInven[i]), EquipmentInven.end());
                            return true;
                        }
                    }
                }

                for (int i = 0; i < ConsumptionInven.size(); ++i)
                {
                    if (ConsumptionInven[i].first->GetName() == name)
                    {
                        if (ConsumptionInven[i].second > 1)
                        {
                            ConsumptionInven[i].second -= Quantity;
                            return true;
                        }
                        else if (ConsumptionInven[i].second == 1)
                        {
                            ConsumptionInven.erase(remove(ConsumptionInven.begin(), ConsumptionInven.end(),
                                ConsumptionInven[i]), ConsumptionInven.end());
                            return true;
                        }
                    }
                }

                for (int i = 0; i < EtcInven.size(); ++i)
                {
                    if (EtcInven[i].first->GetName() == name)
                    {
                        if (EtcInven[i].second > 1)
                        {
                            EtcInven[i].second -= Quantity;
                            return true;
                        }
                        else if (EtcInven[i].second == 1)
                        {
                            EtcInven.erase(remove(EtcInven.begin(), EtcInven.end(),
                                EtcInven[i]), EtcInven.end());
                            return true;
                        }
                    }
                }
            }
        case 2:
            break;
        default:
            cout << "잘못된 입력입니다.\n";
        }
        return false;
    }
}
