#pragma once
#include "IInteractable.h"
#include <string>
#include <vector>

class SFightable : public IInteractable
{
protected:
	int	mHealth{ 0 };
	int	mAttack{ 0 };

public:
	SFightable() {}
	SFightable(int health, int attack) : mHealth{health}, mAttack(attack) {}
	virtual ~SFightable() = default;
	virtual void Interact() = 0;
};

