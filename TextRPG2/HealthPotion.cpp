#include "HealthPotion.h"
#include "Character.h"
#include <iostream>
HealthPotion::HealthPotion()
    : Name("Red Potion"), HealthRestore(50) {}

string HealthPotion::GetName()
{
    return Name;
}

bool HealthPotion::Use(Character *character)
{
    character->SetHealth(character->GetHealth() + HealthRestore);
    cout << "체력을 " << HealthRestore << " 회복했습니다." << endl;
    return true;
}