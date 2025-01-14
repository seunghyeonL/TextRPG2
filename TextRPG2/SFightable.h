#pragma once
#include "IInteractable.h"
#include <string>
#include <vector>

class SFightable : public IInteractable
{
protected:
	double	mHealth{ 0 };
	double	mAttack{ 0 };

public:
	virtual ~SFightable() = default;
	virtual void Interact() = 0;
};

