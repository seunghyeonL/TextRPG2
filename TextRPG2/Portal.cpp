#include "Portal.h"
#include "GameManager.h"
#include "Character.h"
#include "EventLoop.h"

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
	
}

void Portal::SetDestination(Level* Level_Dest)
{
	Destination = Level_Dest;
}

void Portal::Interact()
{
	auto m_pGameManager = GameManager::Get_Instance();
	Character* character = Character::GetInstance();
	character->SetPosition(DestPos.X, DestPos.Y);
	EventLoop* eventLoop = EventLoop::Get_Instance();
	eventLoop->AddTask([m_pGameManager, this]()->void {
		m_pGameManager->Change_Level(this->Destination);
		//m_pGameManager->Update();
	});
	
}

