#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class GreatSword : public IEquipmentItem
{
private:
    const string Name;

public:
    GreatSword();
    string GetName() override;
};

