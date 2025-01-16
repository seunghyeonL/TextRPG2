#pragma once
#include "GameManager.h"
#include "SFightable.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class IMonster: public SFightable
{
public:
	enum class DropTable {
		장비,
		소비,
		기타
	};

protected:
	IMonster();
	virtual ~IMonster() = default;
	vector<IEquipmentItem*> EquipmentItems;   // 장비 아이템들
	vector<IConsumptionItem*> ConsumableItems;  // 소비 아이템들
	vector<IEtcItem*> OtherItems;       // 기타 아이템들

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
	virtual vector<IItem*> DropRandomItem();

	string		mName{};
	
public:
	virtual void Free();
	virtual void Update() = 0;
	virtual void Interact() = 0;
};