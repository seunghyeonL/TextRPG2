#pragma once
#include <string>

using namespace std;

class IMonster abstract
{
protected:
	IMonster();
	virtual ~IMonster() = default;

public:
	/**
	* ���� = 0�� ���� ���������Լ���� ���̸� ���� �ϴ� ��
	* �ڽ�Ŭ������ = 0 �� ���� �Լ��� ������ �����ؾߵ�	*/
	virtual void Initialize(string name, int health, int attack) = 0;
	virtual void Update() = 0;
	
	virtual string GetName() const { return mName; }

	virtual int GetHealth() const { return mHealth; }
	virtual int GetAttack() const { return mAttack; }

protected:
	string		mName{};
	int			mHealth{ 0 };
	int			mAttack{ 0 };
public:
	virtual void Free();
};