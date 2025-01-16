#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class Branch : public IEquipmentItem
{
private:
    const string Name;

public:
    Branch();
    string GetName() override;
};

