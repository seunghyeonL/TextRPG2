#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class HeavySword : public IEquipmentItem
{
private:
    const string Name;

public:
    HeavySword();
    string GetName() override;
};

