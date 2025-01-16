#include "Goblin.h"
#include "HealthPotion.h"
#include "GreenLeatherHelm.h"
#include "GoblinKnife.h"


Goblin::Goblin()
	: IMonster{}
{
}

/* 이렇게 이니셜라이즈에서 직접 초기화 해도 되고 위에서 생성자로 초기화 해도 됨*/

void Goblin::Initialize(string name, double health, double attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;

	GreenLeatherHelm* helm = new GreenLeatherHelm();
	HealthPotion* potion = new HealthPotion();
	GoblinKnife* mass = new GoblinKnife();

	EquipmentItems.push_back(helm);
	ConsumableItems.push_back(potion);
	OtherItems.push_back(mass);
}

void Goblin::Update()
{
}

//void Goblin::Interact() {
//
//}

Goblin *Goblin::Create(string name, double health, double attack)
{
	Goblin *pGoblin = new Goblin();

	pGoblin->Initialize(name, health, attack);

	return pGoblin;
}

Goblin *Goblin::CreateBoss(string name, double health, double attack)
{
	Goblin *pGoblin = new Goblin();

	pGoblin->Initialize(name, health, attack);

	return pGoblin;
}

void Goblin::Free()
{
	IMonster::Free();
}
