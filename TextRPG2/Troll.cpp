#include "Troll.h"

Troll::Troll()
	: IMonster{}
{
}

void Troll::Initialize(string name, double health, double attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Troll::Update()
{

}

//void Troll::Interact() {
//
//}

Troll* Troll::Create(string name, double health, double attack)
{
	Troll* pTroll = new Troll();

	pTroll->Initialize(name, health, attack);

	return pTroll;
}

Troll* Troll::CreateBoss(string name, double health, double attack)
{
	Troll* pTroll = new Troll();

	pTroll->Initialize(name, health, attack);

	return pTroll;
}

void Troll::Free()
{
	IMonster::Free();
}
