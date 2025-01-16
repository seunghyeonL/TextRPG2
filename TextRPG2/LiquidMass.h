#pragma once

#include "IEtcItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class LiquidMass : public IEtcItem
{
private:
    const string Name;

public:
    LiquidMass();
    string GetName() override;
};

