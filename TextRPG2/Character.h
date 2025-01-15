#pragma once
#include "Client_Defines.h"
#include "IItem.h"

#include "Inventory.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

class Character
{
private:
	static Character* Instance;
	string Name;
	int Level;
	int MaxLevel;
	double Health;		  // 체력
	double MaxHealth;	  // 최대 체력
	double Attack;		  // 공격력
	double Experience;	  // 경험치
	double MaxExperience; // 최대 경험치
	shared_ptr<Inventory> Inven;

	class GameManager* pGameManager{ nullptr };
	Character(string name);
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

public:
	static Character * GetInstance(string name = "");
	string GetName();
	int GetLevel();
	void SetLevel(int level);
	double GetHealth();
	void SetHealth(double health);
	double GetAttack();
	void SetAttack(double attack);
	void TakeDamage(double damage);
	double GetExperience();
	double GetMaxExperience();
	double GetGold();
	void DisplayStatus();
	void DisplayInventory();
	void LevelUp();
	void AddExperience(double amount);
	shared_ptr<Inventory> GetInven();
};