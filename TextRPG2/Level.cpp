#include "Level.h"

Level::Level()
	: m_pGameManager{ GameManager::Get_Instance() }
{

}

void Level::Initialize()
{

}

void Level::Update()
{
}

void Level::Render()
{

}

void Level::Clear_Resources()
{

}

void Level::Free()
{
	system("cls");
	delete this;
}
