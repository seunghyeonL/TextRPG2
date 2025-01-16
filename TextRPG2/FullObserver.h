#pragma once
#include "IHealthObserver.h"

class FullObserver: public IHealthObserver
{
public:
	void Update(double health, string name, bool& IsActive) override {
		cout << name << ": 체력이 풀입니다." << '\n';
	}
};