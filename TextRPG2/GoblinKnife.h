#pragma once

#include "IEtcItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class GoblinKnife : public IEtcItem
{
private:
    const string Name;

public:
    GoblinKnife();
    string GetName() override;
};

