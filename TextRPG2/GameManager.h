#pragma once
#include "Character.h"
#include "Client_Defines.h"
using namespace std;

class GameManager
{
	DECLARE_SINGLETON(GameManager)
private:
	GameManager();
	virtual ~GameManager() = default;

public: /* For.Base */
	void Initialize();
	void Update();
	void Render();

	void DisableEcho();
	void EnableEcho();

	int* GetPlayerPosX() { return &m_iPlayerPosX; }
	int* GetPlayerPosY() { return &m_iPlayerPosY; }

public: /* For.Input_Manager */
	bool KeyPressedThisFrame();

	bool Key_Pressing(unsigned int _iKey);
	bool Key_Down(unsigned int _iKey);
	bool Key_Up(unsigned int _iKey);

public: /* For.Level_Manager */
	void Change_Level(class Level* pNewLevel);

public:
	//class IMonster* GenerateMonster(int level);

	class IMonster* GenerateMonster(int level);

	void StartGame();

	void Battle(Character* player);

	void VisitShop(Character* player);

	void Exit();


private:
	class Level_Manager* m_pLevel_Manager{ nullptr };
	class Input_Manager* m_pInput_Manager{ nullptr };

	int m_iPlayerPosX{ 0 };
	int m_iPlayerPosY{ 0 };
public:
	static GameManager* Create();
	virtual void Free();
};