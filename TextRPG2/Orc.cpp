#include "Orc.h"

Orc::Orc()
	: IMonster{}
{
}

void Orc::Initialize(string name, double health, double attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Orc::Update()
{

}

//void Orc::Interact() {
//
//}

Orc* Orc::Create(string name, double health, double attack)
{
	Orc* pOrc = new Orc();

	pOrc->Initialize(name, health, attack);

	return pOrc;
}

Orc* Orc::CreateBoss(string name, double health, double attack)
{
	Orc* pOrc = new Orc();

	pOrc->Initialize(name, health, attack);

	return pOrc;
}

void Orc::Free()
{
	IMonster::Free();
}
