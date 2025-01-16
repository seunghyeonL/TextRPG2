#pragma once
#include "IHealthObserver.h"

class DeathObserver: public IHealthObserver
{
public:
	void Update(double health, string name, bool& IsActive) override {
		if (health <= 0) {
			cout << name << ": 크어얽!" << '\n';
			IsActive = false;
		}
	}
};

