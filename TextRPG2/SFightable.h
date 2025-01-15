#pragma once
#include "IInteractable.h"
#include "IHealthObserver.h"
#include <string>
#include <vector>

class SFightable : public IInteractable
{
protected:
	int	mHealth{ 100 };
	int	mAttack{ 100 };
	vector<IHealthObserver*> Observers;

public:
	SFightable();
	SFightable(int health, int attack);
	virtual ~SFightable() = default;
	virtual void Interact() = 0;
};

