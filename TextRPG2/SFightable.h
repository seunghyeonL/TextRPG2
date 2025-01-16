#pragma once
#include "IInteractable.h"
#include "IHealthObserver.h"
#include <string>
#include <vector>

class SFightable : public IInteractable
{
protected:
	double mHealth{100};
	double mAttack{100};
	vector<IHealthObserver *> Observers;

public:
	SFightable();
	SFightable(double health, double attack);
	virtual ~SFightable() = default;
	virtual void Interact() = 0;
};
