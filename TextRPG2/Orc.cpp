#include "Orc.h"

Orc::Orc()
	: IMonster{}
{
}

/* �̷��� �̴ϼȶ������ ���� �ʱ�ȭ �ص� �ǰ� ������ �����ڷ� �ʱ�ȭ �ص� ��*/
void Orc::Initialize(string name, int health, int attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Orc::Update()
{

}

Orc* Orc::Create(string name, int health, int attack)
{
	Orc* pOrc = new Orc();

	pOrc->Initialize(name, health, attack);

	return pOrc;
}

void Orc::Free()
{
}
