#include "Level_Dungeon.h"
#include "Level_Main.h"
#include "Level_Shop.h"
#include "Character.h"
#include "Portal.h"
#include "Shop.h"

Level_Shop::Level_Shop()
	: Map{}
{
	Initialize();
}

void Level_Shop::Initialize()
{
	MapType = MAP_SHOP;

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			m_Map.insert({ PosStruct{ i, j }, { ". ", nullptr} });
		}
	}

	Portal* VillagePortal = new Portal(MAP_HEIGHT / 2, 2);
	Interactables.push_back(VillagePortal);
	VillagePortal->SetDestination(MAP_VILLAGE);

	m_Map[PosStruct{ MAP_HEIGHT / 2, MAP_WIDTH - 2 }] = { "마", VillagePortal };
	m_Map[PosStruct{ MAP_HEIGHT / 2, MAP_WIDTH - 1 }] = { "을", VillagePortal };

	m_Map[PosStruct{ MAP_HEIGHT / 2, 2 }] = { "S ", VillagePortal };

	Character* pCharacter = Character::GetInstance();
	PosStruct cPos = pCharacter->GetPosition();

	m_Map[cPos] = { "A ", nullptr };
}

void Level_Shop::Update() 
{
	Character* pCharacter = Character::GetInstance();
	PosStruct CurPos = pCharacter->GetPosition();

	m_Map[CurPos] = { ". ", nullptr };

	if (m_pGameManager->Key_Down(VK_UP))
	{
		if (CurPos.X > 0)
		{
			PosStruct NextPos = PosStruct{ CurPos.X - 1, CurPos.Y };

			IInteractable* Interactable = m_Map[NextPos].second;

			if (Interactable)
			{
				if (CurPos.X < MAP_WIDTH / 2)
				{
					CurView = VIEW_SHOP;
				}
				else
				{
					Interactable->Interact();
					//system("cls");
					if (!Interactable->GetIsActive()) {
						delete Interactable;
						m_Map[NextPos] = { ". ", nullptr };
					}
				}
			}
			else
			{
				CurPos.X--;
				pCharacter->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_LEFT))
	{
		if (CurPos.Y > 0)
		{
			PosStruct NextPos = PosStruct{ CurPos.X, CurPos.Y - 1 };
			IInteractable* Interactable = m_Map[NextPos].second;
			if (Interactable)
			{
				if (CurPos.X < MAP_WIDTH / 2 + 1)
				{
					CurView = VIEW_SHOP;

				}
				else
				{
					Interactable->Interact();
					//system("cls");
					if (!Interactable->GetIsActive()) {
						delete Interactable;
						m_Map[NextPos] = { ". ", nullptr };
					}
				}
			}
			else
			{
				CurPos.Y--;
				pCharacter->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_RIGHT))
	{
		if (CurPos.Y < MAP_HEIGHT - 1)
		{
			PosStruct NextPos = PosStruct{ CurPos.X, CurPos.Y + 1 };
			IInteractable* Interactable = m_Map[NextPos].second;
			if (Interactable)
			{
				if (CurPos.X < MAP_WIDTH / 2)
				{
					CurView = VIEW_SHOP;

				}
				else
				{
					Interactable->Interact();
					//system("cls");
					if (!Interactable->GetIsActive()) {
						delete Interactable;
						m_Map[NextPos] = { ". ", nullptr };
					}
				}
			}
			else
			{
				CurPos.Y++;
				pCharacter->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_DOWN))
	{
		if (CurPos.X < MAP_WIDTH - 1)
		{
			PosStruct NextPos = PosStruct{ CurPos.X + 1, CurPos.Y };
			IInteractable* Interactable = m_Map[NextPos].second;
			if (Interactable)
			{
				if (CurPos.X < MAP_WIDTH / 2)
				{
					CurView = VIEW_SHOP;
				}
				else
				{
					Interactable->Interact();
					//system("cls");
					if (!Interactable->GetIsActive()) {
						delete Interactable;
						m_Map[NextPos] = { ". ", nullptr };
					}
				}
			}
			else
			{
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

void Level_Shop::Render()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++) {
			Buffer += m_Map[PosStruct{ i, j }].first;
		}
		Buffer.push_back(L'\n');
	}
	if (CurView != preView)
	{
		system("cls");
		preView = CurView;
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
	case VIEW_SHOP:
		preView = VIEW_SHOP;
		system("cls");
		if (GameManager::Get_Instance()->VisitShop() == false)
			CurView = VIEW_MAP;
		break;
	case VIEW_EQUIPMENTSLOTS:
		preView = VIEW_EQUIPMENTSLOTS;
		system("cls");
		if (Character::GetInstance()->DisplayEquipmentSlots() == true)
			CurView = VIEW_MAP;
		
		break;
	}
	
	cout << "TAB : 스탯창\tE : 장비창\tI : 인벤토리\tESC : 종료" << endl;
	Buffer.clear();
}

void Level_Shop::Free()
{
	Map::Free();
}
