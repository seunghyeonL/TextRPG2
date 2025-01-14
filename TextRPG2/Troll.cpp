#include "Troll.h"

Troll::Troll()
	: IMonster{}
{
}

void Troll::Initialize(string name, int health, int attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Troll::Update()
{

}

Troll* Troll::Create(string name, int health, int attack)
{
	Troll* pTroll = new Troll();

	pTroll->Initialize(name, health, attack);

	return pTroll;
}

Troll* Troll::CreateBoss(string name, int health, int attack)
{
	Troll* pTroll = new Troll();

	pTroll->Initialize(name, health, attack);

	return pTroll;
}

void Troll::Free()
{
}
