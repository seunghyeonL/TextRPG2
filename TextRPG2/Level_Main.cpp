#include "Client_Defines.h"
#include "Level_Main.h"
#include "Level_Dungeon.h"
#include "Level_Shop.h"
#include "Portal.h"
#include "Character.h"

Level_Main::Level_Main()
	: Map{}
{
	Initialize();
}

void Level_Main::Initialize()
{
	MapType = MAP_VILLAGE;

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			m_Map.insert({ PosStruct{ i, j }, { ". ", nullptr} });
		}
	}

	Portal* DungeonPortal = new Portal(MAP_HEIGHT - 2, MAP_WIDTH / 2);
	Portal* ShopPortal = new Portal(MAP_HEIGHT / 2, MAP_WIDTH - 3);

	Interactables.push_back(DungeonPortal);
	Interactables.push_back(ShopPortal);

	DungeonPortal->SetDestination(MAP_DUNGEON);
	ShopPortal->SetDestination(MAP_SHOP);

	m_Map[PosStruct{ 0, MAP_WIDTH / 2 }] = { "던", DungeonPortal };
	m_Map[PosStruct{ 0, MAP_WIDTH / 2 + 1 }] = { "전", DungeonPortal };

	m_Map[PosStruct{ MAP_HEIGHT / 2, 0 }] = { "상", ShopPortal };
	m_Map[PosStruct{ MAP_HEIGHT / 2, 1 }] = { "점", ShopPortal };

	Character* pCharacter = Character::GetInstance();

	PosStruct cPos = pCharacter->GetPosition();

	m_Map[cPos] = { "A ", nullptr };
}

void Level_Main::Update() {
	auto pCharacter = Character::GetInstance();
	PosStruct CurPos = pCharacter->GetPosition();

	m_Map[CurPos] = { ". ", nullptr };

	if (m_pGameManager->Key_Down(VK_UP))
	{
		if (CurPos.X > 0) {
			auto Interactable = m_Map[PosStruct{ CurPos.X - 1, CurPos.Y }].second;
			if (Interactable) {
				Interactable->Interact();
				return;
			}
			else {
				CurPos.X--;
				pCharacter->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_LEFT))
	{
		if (CurPos.Y > 0) {
			auto Interactable = m_Map[PosStruct{ CurPos.X, CurPos.Y - 1 }].second;
			if (Interactable) {
				Interactable->Interact();
				return;
			}
			else {
				CurPos.Y--;
				pCharacter->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_RIGHT))
	{
		if (CurPos.Y < MAP_HEIGHT - 1) {
			auto Interactable = m_Map[PosStruct{ CurPos.X, CurPos.Y + 1 }].second;
			if (Interactable) {
				Interactable->Interact();
				return;
			}
			else {
				CurPos.Y++;
				pCharacter->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_DOWN))
	{
		if (CurPos.X < MAP_WIDTH - 1) {
			auto Interactable = m_Map[PosStruct{ CurPos.X + 1, CurPos.Y }].second;
			if (Interactable) {
				Interactable->Interact();
				return;
			}
			else {
				CurPos.X++;
				pCharacter->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_TAB))
	{
		if (CurView == VIEW_MAP || CurView == VIEW_INVENTORY)
			CurView = VIEW_STATUS;
		else
			CurView = VIEW_MAP;
		system("cls");
	}
	else if (m_pGameManager->Key_Down(0x49))
	{
		if (CurView == VIEW_MAP || CurView == VIEW_STATUS)
			CurView = VIEW_INVENTORY;
		else
			CurView = VIEW_MAP;
		system("cls");
	}


	m_Map[CurPos] = { "A ", nullptr };
}

void Level_Main::Render()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++) {
			Buffer += m_Map[PosStruct{ i, j }].first;
		}
		Buffer.push_back(L'\n');
	}

	gotoxy(0, 0);

	switch (CurView)
	{
	case VIEW_MAP:
		Render_TextMap();
		cout << Buffer;
		break;
	case VIEW_STATUS:
		Character::GetInstance()->DisplayStatus();
		break;
	case VIEW_INVENTORY:
		Character::GetInstance()->DisplayInventory();
		break;
	}

	cout << "TAB : 스탯창\tI : 인벤토리\tESC : 종료" << endl;
	Buffer.clear();
}

void Level_Main::Free()
{
	Map::Free();
}
