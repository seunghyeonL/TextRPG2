#include "Portal.h"
#include "Character.h"

Portal::Portal(int PosX, int PosY, int DestPosX, int DestPosY) {
	Pos.X = PosX;
	Pos.Y = PosY;
	DestPos.X = DestPosX;
	DestPos.Y = DestPosY;
}

Portal::~Portal()
{
	if(Destination != nullptr)
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

void Portal::Interact()
{
	auto character = Character::GetInstance();
	character->SetPosition(DestPos.X, DestPos.Y);
	m_pGameManager->Change_Level(Destination);
	m_pGameManager->Update();
}

