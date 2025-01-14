#pragma once

#include "IMonster.h"

class Slime : public IMonster
{
private:
	/*
	�����ڸ� private ���� �ع����� �����Ҵ��� ������. �������
	�׷��� Create��� �Լ��� ���� ���� �����ϰ� �� �� �ִ�.	*/
	Slime();
	virtual ~Slime() = default;

public: /* IMonster �θ� Ŭ�������� �޾ƿ� �Լ��� */
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;
	virtual void Interact() override;

public: /* ���� �����Ҵ��� ������ִ� �Լ� */
	static Slime* Create(string name, int health, int attack);
	static Slime* CreateBoss(string name, int health, int attack);
	virtual void Free() override;
};