#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class BoneArmor : public IEquipmentItem
{
private:
    const string Name;

public:
    BoneArmor();
    string GetName() override;
};

