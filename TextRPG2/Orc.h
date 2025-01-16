#pragma once

#include "IMonster.h"

class Orc : public IMonster
{
private:
	Orc();
	virtual ~Orc() = default;

public:
	virtual void Initialize(string name, double health, double attack) override;
	virtual void Update() override;
	//virtual void Interact() override;

public:
	static Orc* Create(string name, double health, double attack);
	static Orc* CreateBoss(string name, double health, double attack);
	virtual void Free() override;
};