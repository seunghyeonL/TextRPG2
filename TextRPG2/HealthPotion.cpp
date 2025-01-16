#include "HealthPotion.h"
#include "Character.h"
#include <iostream>
HealthPotion::HealthPotion()
    : Name("RedPotion"), HealthRestore(50) {}

string HealthPotion::GetName()
{
    return Name;
}

bool HealthPotion::Use(Character *character)
{
    LasyCout lasyCout = LasyCout();
    stringstream ss;

    character->SetHealth(character->GetHealth() + HealthRestore);
    ss << "체력을 " << HealthRestore << " 회복했습니다." << endl;
    lasyCout(ss.str());
    ss.str("");
    return true;
}