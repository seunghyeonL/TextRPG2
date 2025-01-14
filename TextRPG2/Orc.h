#pragma once

#include "IMonster.h"

class Orc : public IMonster
{
private:
	Orc();
	virtual ~Orc() = default;

public:
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;
	virtual void Interact() override;

public:
	static Orc* Create(string name, int health, int attack);
	static Orc* CreateBoss(string name, int health, int attack);
	virtual void Free() override;
};