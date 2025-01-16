#pragma once
#include "IInteractable.h"
#include "IHealthObserver.h"
#include <string>
#include <vector>

class SFightable : public IInteractable
{
protected:
	double mHealth;
	double mAttack;
	vector<IHealthObserver *> Observers;

public:
	SFightable();
	virtual ~SFightable() = default;
	virtual void Interact() = 0;
};