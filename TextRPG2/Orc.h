#pragma once

#include "IMonster.h"

class Orc : public IMonster
{
private:
	/*
	�����ڸ� private ���� �ع����� �����Ҵ��� ������. �������
	�׷��� Create��� �Լ��� ���� ���� �����ϰ� �� �� �ִ�.	*/
	Orc();
	virtual ~Orc() = default;

public: /* IMonster �θ� Ŭ�������� �޾ƿ� �Լ��� */
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;

public: /* ���� �����Ҵ��� ������ִ� �Լ� */
	static Orc* Create(string name = "", int health = 10, int attack = 5);
	virtual void Free() override;
};

/* �̷��� public���� �����ڿ� ���ڰ��� �־ �ʱ�ȭ�� �⺻
* 
class Orc : public IMonster
{
public:
		Orc(string name, int health, int attack);   <--------
		virtual ~Orc() = default;

public:
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;

public:
	virtual void Free() override;
};
*/