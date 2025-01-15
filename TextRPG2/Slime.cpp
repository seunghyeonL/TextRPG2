#include "Slime.h"

Slime::Slime()
	: IMonster{}
{
}

/* �̷��� �̴ϼȶ������ ���� �ʱ�ȭ �ص� �ǰ� ������ �����ڷ� �ʱ�ȭ �ص� ��*/
void Slime::Initialize(string name, int health, int attack)
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

Slime* Slime::Create(string name, int health, int attack)
{
	Slime* pSlime = new Slime();

	pSlime->Initialize(name, health, attack);

	return pSlime;
}

Slime* Slime::CreateBoss(string name, int health, int attack)
{
	Slime* pSlime = new Slime();

	pSlime->Initialize(name, health, attack);

	return pSlime;
}

void Slime::Free()
{
	IMonster::Free();
}
