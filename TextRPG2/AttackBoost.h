#pragma once
#include <iostream>
#include <string>
#include "IItem.h"

using namespace std;

class Character;

class AttackBoost : IItem
{
private:
    string Name;
    int AttackIncrease;

public:
    AttackBoost();
    string GetName() override;
    void Use(Character *character) override;
};