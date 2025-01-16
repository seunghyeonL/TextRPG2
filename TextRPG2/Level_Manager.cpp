#include "Level_Manager.h"
#include "Level.h"
#include "Map.h"
#include "Level_Main.h"
#include "Level_Dungeon.h"
#include "Level_Shop.h"

Level_Manager::Level_Manager()
{
}

void Level_Manager::Initialize()
{
}

void Level_Manager::Update()
{
	if (nullptr == m_pCurrentLevel)
		return;

	m_pCurrentLevel->Update();
}

void Level_Manager::Render()
{
	if (nullptr == m_pCurrentLevel)
		return;

	m_pCurrentLevel->Render();
}

void Level_Manager::Change_Level(Level* pNewLevel)
{
	if (m_pCurrentLevel != nullptr)
		m_pCurrentLevel->Free();

	system("cls");
	m_pCurrentLevel = pNewLevel;
}

Level_Manager* Level_Manager::Create()
{
	Level_Manager* pInstance = new Level_Manager();

	pInstance->Initialize();

	return pInstance;
}

Level* Level_Manager::CreateMap(MAP MAP_ENUM)
{
	Level* result{ nullptr };

	switch (MAP_ENUM) {
	case MAP_VILLAGE:
		result = new Level_Main();
		break;
	case MAP_DUNGEON:
		result = new Level_Dungeon();
		break;
	case MAP_SHOP:
		result = new Level_Shop();
		break;
	case MAP_END:
		result = nullptr;
		break;
	}

	return result;
}

void Level_Manager::Free()
{
	if (nullptr != m_pCurrentLevel) {
		m_pCurrentLevel->Free();
	}
	delete this;
}
