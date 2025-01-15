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

	EquipmentItems.push_back("1레벨 장갑");
	EquipmentItems.push_back("1레벨 투구");
	ConsumableItems.push_back("HealthPotion");
	ConsumableItems.push_back("AttackBoost");
	OtherItems.push_back("액체 덩어리");
}

void Slime::Update()
{

}

void Slime::Interact() {

}

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
}
