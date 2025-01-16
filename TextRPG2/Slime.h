#pragma once

#include "IMonster.h"

class Slime : public IMonster
{
private:
	Slime();
	virtual ~Slime() = default;

public:
	virtual void Initialize(string name, double health, double attack) override;
	virtual void Update() override;
	//virtual void Interact() override;

public:
	static Slime* Create(string name, double health, double attack);
	static Slime* CreateBoss(string name, double health, double attack);
	virtual void Free() override;
};