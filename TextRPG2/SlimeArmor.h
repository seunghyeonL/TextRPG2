#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class SlimeArmor : public IEquipmentItem
{
private:
    const string Name;

public:
    SlimeArmor();
    string GetName() override;
};

