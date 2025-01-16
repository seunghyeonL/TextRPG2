#pragma once

#include "IConsumptionItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class HealthPotion : public IConsumptionItem
{
private:
    const string Name;
    const int HealthRestore;

public:
    HealthPotion();
    string GetName() override;
    bool Use(Character *character) override;
};