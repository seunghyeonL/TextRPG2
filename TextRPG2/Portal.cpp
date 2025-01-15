#include "Portal.h"
#include "GameManager.h"
#include "Character.h"
#include "EventLoop.h"

Portal::Portal(int DestPosX, int DestPosY) {
	DestPos.X = DestPosX;
	DestPos.Y = DestPosY;
}

Portal::~Portal()
{

}

void Portal::Initialize()
{
	
}

void Portal::SetDestination(MAP MAP_ENUM)
{
	Destination = MAP_ENUM;
}

void Portal::Interact()
{
	auto m_pGameManager = GameManager::Get_Instance();
	Character* character = Character::GetInstance();
	character->SetPosition(DestPos.X, DestPos.Y);
	EventLoop* eventLoop = EventLoop::Get_Instance();
	eventLoop->AddTask([m_pGameManager, this]()->void {
		m_pGameManager->Change_Level(m_pGameManager->CreateMap(Destination));
		//m_pGameManager->Update();
	});
}

