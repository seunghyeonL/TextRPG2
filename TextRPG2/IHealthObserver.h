#pragma once
#include "Client_Defines.h"

class IHealthObserver {
public:
	virtual ~IHealthObserver() = default;
	virtual void Update(int health) = 0;
};