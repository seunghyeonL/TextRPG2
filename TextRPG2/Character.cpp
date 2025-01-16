#include <iostream>
#include <string>
#include <sstream>
#include "GameManager.h"
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "ShabbyHelm.h"
#include "GreenLeatherHelm.h"
#include "BoneHelm.h"
#include "ClothArmor.h"
#include "SlimeArmor.h"
#include "BoneArmor.h"
#include "Branch.h"
#include "HeavySword.h"
#include "GreatSword.h"

Character *Character::Instance = nullptr;

Character::Character(string name)
    : Name(name), Level(1), Health(200),
      MaxHealth(MAX_HEALTH), MaxExperience(100), Attack(30), Experience(0), Inven(make_shared<Inventory>()),
      pGameManager{GameManager::Get_Instance()}
{
    HealthPotion *potion = new HealthPotion();
    AttackBoost *AB = new AttackBoost();
    ShabbyHelm* helm = new ShabbyHelm();
    GreenLeatherHelm* gh = new GreenLeatherHelm();
    BoneHelm* bh = new BoneHelm();
    ClothArmor* ca = new ClothArmor();
    SlimeArmor* sa = new SlimeArmor();
    BoneArmor* ba = new BoneArmor();
    Branch* b = new Branch();
    HeavySword* hs = new HeavySword();
    GreatSword* gs = new GreatSword();

    potion->AddToInventory(Inven, 10);
    AB->AddToInventory(Inven, 5);
    helm->AddToInventory(Inven, 1);
    gh->AddToInventory(Inven, 1);
    bh->AddToInventory(Inven, 1);
    ca->AddToInventory(Inven, 1);
    sa->AddToInventory(Inven, 1);
    ba->AddToInventory(Inven, 1);
    b->AddToInventory(Inven, 1);
    hs->AddToInventory(Inven, 1);
    gs->AddToInventory(Inven, 1);
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

void Character::SetMaxHealth(double maxHealth)
{
    MaxHealth = maxHealth;
}

double Character::GetMaxHealth()
{
    return MaxHealth;
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

    // system("pause");
}

void Character::DisplayEquipmentSlots()
{
    cout << "현재 착용중인 장비" << endl;

    if (HelmSlot == nullptr) 
        cout << "투구 : 비어있음" << endl;
    else 
        cout << "투구 : " << HelmSlot->GetName() << endl;
    if (ArmorSlot == nullptr) 
        cout << "갑옷 : 비어있음" << endl;
    else 
        cout << "갑옷 : " << ArmorSlot->GetName() << endl;

    if (WeaponSlot == nullptr) 
        cout << "무기 : 비어있음" << endl;
    else
        cout << "무기 : " << WeaponSlot->GetName() << endl;

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

    int index;
    //cout << "\n사용할 아이템 번호를 입력해주세요.\n";
    cout<<"\n사용할 아이템 번호를 입력해주세요. // 0번 누를시 탈출.\n";
    cin >> index;
    Equip(index - 1);
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

void Character::SetEquipmentSlots(IEquipmentItem* equipItem, EquipmentType type)
{
    switch (type)
    {
    case Helm:
        if (HelmSlot == nullptr)
        {
            HelmSlot = equipItem;
            ApplyItemHealthStatus(equipItem);
            cout << equipItem->GetName() << "을 투구칸에 장착하였습니다." << endl;
        }
        else
        {
            auto ExEquipItem = HelmSlot;
            HelmSlot == nullptr;
            HelmSlot = equipItem;
            ApplyItemHealthStatus(equipItem, ExEquipItem);
            cout << ExEquipItem->GetName() << "을 해제하고 " << equipItem->GetName() << "을 투구칸에 장착하였습니다." << endl;
            Inven->AddToEquipment(ExEquipItem);
        }
        break;
    case Armor:
        if (ArmorSlot == nullptr)
        {
            ArmorSlot = equipItem;
            ApplyItemHealthStatus(equipItem);
            cout << equipItem->GetName() << "을 갑옷칸에 장착하였습니다." << endl;
        }
        else
        {
            auto ExEquipItem = ArmorSlot;
            ArmorSlot == nullptr;
            ArmorSlot = equipItem;
            ApplyItemHealthStatus(equipItem, ExEquipItem);
            cout << ExEquipItem->GetName() << "을 해제하고 " << equipItem->GetName() << "을 갑옷칸에 장착하였습니다." << endl;
            Inven->AddToEquipment(ExEquipItem);
        }
        break;
    case Weapon:
        if (WeaponSlot == nullptr)
        {
            WeaponSlot = equipItem;
            ApplyItemAttackStatus(equipItem);
            cout << equipItem->GetName() << "을 무기칸에 장착하였습니다." << endl;
        }
        else
        {
            auto ExEquipItem = WeaponSlot;
            WeaponSlot == nullptr;
            WeaponSlot = equipItem;
            ApplyItemAttackStatus(equipItem, ExEquipItem);
            cout << ExEquipItem->GetName() << "을 해제하고 " << equipItem->GetName() << "을 무기칸에 장착하였습니다." << endl;
            Inven->AddToEquipment(ExEquipItem);
        }
        break;
    default:
        cout << "잘못된 접근입니다." << endl;
        break;
    }
    Inven->RemoveToEquipment(equipItem);
}

void Character::ApplyItemHealthStatus(IEquipmentItem* equipItem, IEquipmentItem* exEquipItem)
{
    if (exEquipItem == nullptr)
    {
        IncreasedHealth += equipItem->GetHealthIncrease();
        SetMaxHealth(GetHealth() + IncreasedHealth);
    }
    else
    {
        int HealthDiffer = equipItem->GetHealthIncrease() - exEquipItem->GetHealthIncrease();
        IncreasedHealth += HealthDiffer;
        SetMaxHealth(GetHealth() + IncreasedHealth);
    }
}

void Character::ApplyItemAttackStatus(IEquipmentItem* equipItem, IEquipmentItem* exEquipItem)
{
    if (exEquipItem == nullptr)
    {
        IncreasedAttak += equipItem->GetAttackIncrease();
        SetAttack(GetAttack() + IncreasedAttak);
    }
    else
    {
        IncreasedAttak = 0;
        int AttackDiffer = equipItem->GetAttackIncrease() - exEquipItem->GetAttackIncrease();
        IncreasedAttak += AttackDiffer;
        SetAttack(GetAttack() + IncreasedAttak);
    }
}

void Character::Equip(int index)
{
    if (index == -1)
    {
        cout << "0번 누름" << endl;
    }

    if (index >= 0 && index < Inven->GetEquipmentInven().size())
    {
        cout << Inven->GetEquipmentInven()[index]->GetName() << "을(를) 착용합니다.\n";
        Inven->GetEquipmentInven()[index]->Equip();
    }
    
   
}
