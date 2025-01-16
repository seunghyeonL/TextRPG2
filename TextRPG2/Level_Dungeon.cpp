#include "Level_Main.h"
#include "Level_Dungeon.h"
#include "Level_Shop.h"
#include "Portal.h"
#include "Character.h"

Level_Dungeon::Level_Dungeon()
	: Map{}
{
	Initialize();
}

void Level_Dungeon::Initialize()
{
	MapType = MAP_DUNGEON;

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			m_Map.insert({ PosStruct{ i, j }, { ". ", nullptr} });
		}
	}

	Portal* VillagePortal = new Portal(1, MAP_WIDTH / 2);
	Interactables.push_back(VillagePortal);
	VillagePortal->SetDestination(MAP_VILLAGE);

	m_Map[PosStruct{ MAP_HEIGHT - 1, MAP_WIDTH / 2 }] = { "마", VillagePortal };
	m_Map[PosStruct{ MAP_HEIGHT - 1, MAP_WIDTH / 2 + 1 }] = { "을", VillagePortal };

	Character* pCharacter = Character::GetInstance();
	PosStruct cPos = pCharacter->GetPosition();

	m_Map[cPos] = { "A ", nullptr };

	GameManager* pGameManager = GameManager::Get_Instance();
	int CharacterLevel = pCharacter->GetLevel();
	IMonster* pMonster1 = pGameManager->GenerateMonster(CharacterLevel);
	IMonster* pMonster2 = pGameManager->GenerateMonster(CharacterLevel);
	IMonster* pMonster3 = pGameManager->GenerateMonster(CharacterLevel);

	m_Map[PosStruct{ 5, 5 }] = { "M ", pMonster1 };
	m_Map[PosStruct{ 3, 5 }] = { "M ", pMonster2 };
	m_Map[PosStruct{ 3, 9 }] = { "M ", pMonster3 };
}

void Level_Dungeon::Update() 
{
	Map::Update();
}

void Level_Dungeon::Render()
{
	Map::Render();
}

void Level_Dungeon::Free()
{
	Map::Free();
}
