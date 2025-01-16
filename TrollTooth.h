#pragma once

#include "IEtcItem.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class TrollTooth : public IEtcItem
{
private:
    const string Name;

public:
    TrollTooth();
    string GetName() override;
};

