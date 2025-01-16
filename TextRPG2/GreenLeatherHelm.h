#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class GreenLeatherHelm : public IEquipmentItem
{
private:
    const string Name;

public:
    GreenLeatherHelm();
    string GetName() override;
};

