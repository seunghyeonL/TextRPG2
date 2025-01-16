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
	string mName{"NoNamed"};
	vector<IHealthObserver *> Observers;

public:
	SFightable();
	virtual ~SFightable();
	virtual void HealthUpdate()
	{
		for (auto Observer : Observers)
		{
			Observer->Update(mHealth, mName, IsActive);
		}
	}
	virtual void Interact() = 0;
};