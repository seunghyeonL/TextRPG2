#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class ClothArmor : public IEquipmentItem
{
private:
    const string Name;

public:
    ClothArmor();
    string GetName() override;
};

