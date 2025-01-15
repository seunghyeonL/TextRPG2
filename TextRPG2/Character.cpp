#include <iostream>
#include <string>
#include <sstream>
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Character *Character::Instance = nullptr;

Character::Character(string name)
    : Name(name), Level(1), Health(200),
      MaxHealth(MAX_HEALTH), MaxExperience(100), Attack(30), Experience(0), Inven(make_shared<Inventory>())
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
    
    string input;
    int index;

    while (true) {
        cout << "사용할 아이템 번호를 입력하세요: ";
        getline(cin, input); // 한 줄 입력 받기
        // 문자열을 정수로 변환 시도
        stringstream ss(input);
        if (!(ss >> index) || !(ss.eof())) {
            // 변환 실패 또는 남은 데이터가 있는 경우
            cout << "잘못된 입력입니다. 정수를 입력하세요.\n";
            continue;
        }

        // 유효한 범위 확인
        if (index < 0 || index >= Inven->GetInventory().size()) {
            cout << "입력한 번호가 유효하지 않습니다. 다시 시도하세요.\n";
        }
        else {
            break; // 유효한 입력이면 루프 종료
        }
    }
    Inven->UseItem(index);
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
