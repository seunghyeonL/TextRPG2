#pragma once

#include "IEtcItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class CanineMass : public IEtcItem
{
private:
    const string Name;

public:
    CanineMass();
    string GetName() override;
};

