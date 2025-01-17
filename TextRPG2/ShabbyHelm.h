#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class ShabbyHelm : public IEquipmentItem
{
private:
    const string Name;

public:
    ShabbyHelm();
    string GetName() override;
};

