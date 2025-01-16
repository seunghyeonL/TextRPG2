#include "Map.h"
#include "Character.h"

void Map::gotoxy(int x, int y) {
	COORD coord;
	coord.X = SHORT(x);
	coord.Y = SHORT(y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Map::Render_TextMap()
{
	switch (MapType)
	{
	case MAP_VILLAGE:
		cout << "MAP : 마을" << endl;
		break;
	case MAP_DUNGEON:
		cout << "MAP : 던전" << endl;
		break;
	case MAP_SHOP:
		cout << "MAP : 상점" << endl;
		break;
	}
}

void Map::Update()
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
				Interactable->Interact();
				//system("cls");
				if (!Interactable->GetIsActive()) {
					delete Interactable;
					m_Map[NextPos] = {". ", nullptr};
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
				Interactable->Interact();
				//system("cls");
				if (!Interactable->GetIsActive()) {
					delete Interactable;
					m_Map[NextPos] = { ". ", nullptr };
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
				Interactable->Interact();
				//system("cls");
				if (!Interactable->GetIsActive()) {
					delete Interactable;
					m_Map[NextPos] = { ". ", nullptr };
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
				Interactable->Interact();
				//system("cls");
				if (!Interactable->GetIsActive()) {
					delete Interactable;
					m_Map[NextPos] = { ". ", nullptr };
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



void Map::Free()
{
	
	Level::Free();
}

