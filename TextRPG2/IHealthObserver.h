#pragma once
#include "Client_Defines.h"

class IHealthObserver
{
public:
	virtual ~IHealthObserver() = default;
	virtual void Update(double health, string name, bool& IsActive) = 0;
};
