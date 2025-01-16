#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class LeatherShoes : public IEquipmentItem
{
private:
    const string Name;

public:
    LeatherShoes();
    string GetName() override;
    void Equip(Character* character) override;
};
