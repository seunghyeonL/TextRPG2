#pragma once
#include "GameManager.h"
#include "SFightable.h"
#include <string>

using namespace std;

class IMonster: public SFightable
{
protected:
	IMonster();
	virtual ~IMonster() = default;

public:
	/**
	* ���� = 0�� ���� ���������Լ���� ���̸� ���� �ϴ� ��
	* �ڽ�Ŭ������ = 0 �� ���� �Լ��� ������ �����ؾߵ�	*/
	virtual void Initialize(string name, int health, int attack) = 0;
	
	virtual string GetName() const { return mName; }

	virtual int GetHealth() const { return mHealth; }
	virtual int GetAttack() const { return mAttack; }

protected:
	string		mName{};
	
public:
	virtual void Free();
	virtual void Update() = 0;
	virtual void Interact();
};