#pragma once

#include "IEquipmentItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class BoneHelm : public IEquipmentItem
{
private:
    const string Name;

public:
    BoneHelm();
    string GetName() override;
    void Equip(Character* character) override;
};

