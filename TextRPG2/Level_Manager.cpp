#include "Level_Manager.h"
#include "Level.h"

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

void Level_Manager::Change_Level(Level *pNewLevel)
{
	if (m_pCurrentLevel != nullptr)
		m_pCurrentLevel->Free();

	cout << flush;
	cout.clear();
	system("cls");
	m_pCurrentLevel = pNewLevel;
}

Level_Manager *Level_Manager::Create()
{
	Level_Manager *pInstance = new Level_Manager();

	pInstance->Initialize();

	return pInstance;
}

void Level_Manager::Free()
{
	delete this;
}
