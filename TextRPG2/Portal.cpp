#include "Portal.h"

Portal::~Portal()
{
	Destination->Free();
}

void Portal::Initialize()
{
	m_pGameManager = GameManager::Get_Instance();
}

void Portal::SetDestination(Level* Level_Dest)
{
	Destination = Level_Dest;
}

void Portal::SetPos(int Pos_X, int Pos_Y)
{
	Pos.Pos_X = Pos_X;
	Pos.Pos_Y = Pos_Y;
}

void Portal::Interact()
{
	m_pGameManager->Change_Level(Destination);
}

