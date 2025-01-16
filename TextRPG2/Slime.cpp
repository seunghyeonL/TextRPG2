#include "Slime.h"

Slime::Slime()
	: IMonster{}
{
}

void Slime::Initialize(string name, double health, double attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Slime::Update()
{

}

//void Slime::Interact() {
//
//}

Slime* Slime::Create(string name, double health, double attack)
{
	Slime* pSlime = new Slime();

	pSlime->Initialize(name, health, attack);

	return pSlime;
}

Slime* Slime::CreateBoss(string name, double health, double attack)
{
	Slime* pSlime = new Slime();

	pSlime->Initialize(name, health, attack);

	return pSlime;
}

void Slime::Free()
{
	IMonster::Free();
}
