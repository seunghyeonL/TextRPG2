#pragma once

#include "IMonster.h"

class Slime : public IMonster
{
private:
	Slime();
	virtual ~Slime() = default;

public:
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;

public:
	static Slime* Create(string name, int health, int attack);
	static Slime* CreateBoss(string name, int health, int attack);
	virtual void Free() override;
};