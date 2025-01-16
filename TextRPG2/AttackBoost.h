#pragma once
#include <iostream>
#include <string>
#include "IConsumptionItem.h"

using namespace std;

class Character;

class AttackBoost : public IConsumptionItem
{
private:
    string Name;
    int AttackIncrease;

public:
    AttackBoost();
    string GetName() override;
    bool Use(Character *character) override;
};