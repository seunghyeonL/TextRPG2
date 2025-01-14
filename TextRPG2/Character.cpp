#include <iostream>
#include "Character.h"

Character* Character::Instance = nullptr;

Character::Character(string name)
    : Name(name), Level(1), Health(200),
    MaxHealth(200), MaxExperience(100), Attack(30), Experience(0), Gold(0)
{
}

Character* Character::GetInstance(string name)
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

void Character::SetAttack(double attack)
{
    Attack = attack;
}

void Character::TakeDamage(double damage)
{
    Health -= damage;
    if (Health < 0) Health = 0;
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
    return Gold;
}

void Character::DisplayStatus()
{  
    cout << "\n현재 레벨 : " << Level << "레벨 " << Experience / MaxExperience * 100 << "% 경험치\n";
    cout << "현재 체력 : " << Health << " / " << MaxHealth << " (" << Health / MaxHealth * 100 << "%)\n";
    cout << "현재 공격력 : " << Attack << "\n";
    cout << "현재 보유 골드 : " << Gold << "\n\n";
}

void Character::DisplayInventory()
{
    for (int i = 0; i < Inventory.size(); i++)
    {
        cout << i << ". " << Inventory[i].first->GetName() << ": " << Inventory[i].second << "개\n";
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
    if (Level == MaxLevel) { cout << "\n현재 최대 레벨입니다.\n"; }
}

void Character::UseItem(int index)
{
    if (index >= 0 && index < Inventory.size())
    {
        cout << Inventory[index].first->GetName() << "을(를) 사용합니다.\n";
        Inventory[index].first->Use(GetInstance(Name));
        // 수량 소모
    }
}

void Character::AddExperience(double amount) { Experience += amount; }
void Character::AddGold(double amount) { Gold += amount; }

void Character::AddItem(IItem* item)
{
    for (int i = 0; i < Inventory.size(); i++) {
        if (Inventory[i].first->GetName() == item->GetName()) {
            Inventory[i].second++;
            delete item;
            return;
        }
    }
}
