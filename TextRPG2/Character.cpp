#include <iostream>
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Character *Character::Instance = nullptr;

Character::Character(string name)
    : Name(name), Level(1), Health(200), Attack(30),
      MaxHealth(MAX_HEALTH), MaxExperience(100),  Experience(0), Inven(make_unique<Inventory>())
{
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
    HealthPotion *potion = new HealthPotion();
    AttackBoost *AB = new AttackBoost();
    Inven->AddItem(potion);
    Inven->AddItem(AB);
    if (Inven->GetInventory().empty())
        cout << "인벤토리는 비어있다."
                "\n";

    for (int i = 0; i < Inven->GetInventory().size(); i++)
        cout << i << ". " << Inven->GetInventory()[i].first->GetName() << ": " << Inven->GetInventory()[i].second << "개\n";

    int index;
    cin >> index;
    Inven->UseItem(index);
    for (int i = 0; i < Inven->GetInventory().size(); i++)
        cout << i << ". " << Inven->GetInventory()[i].first->GetName() << ": " << Inven->GetInventory()[i].second << "개\n";
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

shared_ptr<Inventory> Character::GetInven()
{
    return Inven;
}
