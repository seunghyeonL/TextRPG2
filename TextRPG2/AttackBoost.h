#pragma once
#include <iostream>
#include <string>
#include "IItem.h"

using namespace std;

class Character;

class AttackBoost : public IItem
{
private:
    string Name;
    int AttackIncrease;

public:
    AttackBoost();
    string GetName() override;
    bool Use(Character *character) override;
};