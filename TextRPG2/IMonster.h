#pragma once
#include "GameManager.h"
#include "SFightable.h"
#include <string>

using namespace std;

class IMonster: public SFightable
{
public:
	enum class DropItem {
		None,       // 아무것도 떨어지지 않음
		Gold,       // 골드
		Potion,     // 물약
		Weapon,     // 무기
		Armor,      // 방어구
	};

protected:
	IMonster();
	virtual ~IMonster() = default;

public:
	virtual void Initialize(string name, double health, double attack) = 0;
	
	virtual string GetName() const { return mName; }

	virtual double GetHealth() const { return mHealth; }
	virtual void GetDamage(double attack)
	{
		mHealth -= attack;
		if (mHealth <= 0)
		{
			mHealth = 0;
		}
	}
	virtual double GetAttack() const { return mAttack; }

	string		mName{};
	
public:
	virtual void Free();
	virtual void Update() = 0;
	virtual void Interact() = 0;
};