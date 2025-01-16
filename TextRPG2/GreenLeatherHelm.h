#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class GreemLeatherHelm : public IEquipmentItem
{
private:
    const string Name;

public:
    GreemLeatherHelm();
    string GetName() override;
    void Equip(Character* character) override;
};

