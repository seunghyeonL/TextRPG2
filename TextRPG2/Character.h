#pragma once
#include "Client_Defines.h"
#include "IItem.h"
#include "Movable.h"
#include "SFightable.h"

#include "Inventory.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

class Character : public Movable
{
private:
	static Character *Instance;
	string Name;
	int Level;
	int MaxLevel;
	double Health;
	double Attack;
	double MaxHealth;	  // 최대 체력
	double Experience;	  // 경험치
	double MaxExperience; // 최대 경험치
	double IncreasedAttak;
	double IncreasedHealth;
	shared_ptr<Inventory> Inven;
	IEquipmentItem* HelmSlot;
	IEquipmentItem* ArmorSlot;
	IEquipmentItem* WeaponSlot;

	class GameManager *pGameManager{nullptr};
	Character(string name);
	Character(const Character &) = delete;
	Character &operator=(const Character &) = delete;

public:
	static Character *GetInstance(string name = "");
	string GetName();
	int GetLevel();
	void SetLevel(int level);
	double GetHealth();
	void SetHealth(double health);
	double GetAttack();
	void SetMaxHealth(double maxHealth);
	double GetMaxHealth();
	void GetDamage(double attack);
	void SetAttack(double attack);
	void TakeDamage(double damage);
	double GetExperience();
	double GetMaxExperience();
	double GetGold();
	void DisplayStatus();
	void DisplayInventory();
	bool DisplayEquipmentSlots();
	void LevelUp();
	void AddExperience(double amount);
	shared_ptr<Inventory> GetInventory();
	void SetEquipmentSlots(IEquipmentItem* equipItem, EquipmentType type);

	int SellItem();
	int BuyItem();

	void ApplyItemHealthStatus(IEquipmentItem* equipItem, IEquipmentItem* exEquipItem = nullptr);
	void ApplyItemAttackStatus(IEquipmentItem* equipItem, IEquipmentItem* exEquipItem = nullptr);
	void Equip(int index);
};