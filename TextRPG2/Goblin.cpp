#include "Goblin.h"

Goblin::Goblin()
	: IMonster{}
{
}

/* 이렇게 이니셜라이즈에서 직접 초기화 해도 되고 위에서 생성자로 초기화 해도 됨*/
void Goblin::Initialize(string name, int health, int attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Goblin::Update()
{
}

Goblin *Goblin::Create(string name, int health, int attack)
{
	Goblin *pGoblin = new Goblin();

	pGoblin->Initialize(name, health, attack);

	return pGoblin;
}

void Goblin::Free()
{
}
