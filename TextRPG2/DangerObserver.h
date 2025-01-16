#pragma once
#include "IHealthObserver.h"

class DangerObserver: public IHealthObserver
{
public:
	void Update(double health, string name, bool& IsActive) override {
		if (health <= 50) {
			cout << name << ": 체력이 얼마 남지 않았습니다." << endl;
		}
	}
};

