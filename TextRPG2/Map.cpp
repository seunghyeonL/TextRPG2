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
					m_Map[NextPos] = { ". ", nullptr };
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
	
	m_Map[CurPos] = { "A ", nullptr };

	if (m_pGameManager->Key_Down(VK_TAB))
	{
		if (CurView == VIEW_MAP || CurView == VIEW_INVENTORY || CurView == VIEW_EQUIPMENTSLOTS)
			CurView = VIEW_STATUS;
		else
			CurView = VIEW_MAP;
		system("cls");
	}
	else if (m_pGameManager->Key_Down(0x49))
	{
		if (CurView == VIEW_MAP || CurView == VIEW_STATUS || CurView == VIEW_EQUIPMENTSLOTS)
			CurView = VIEW_INVENTORY;
		else
			CurView = VIEW_MAP;
		system("cls");
	}
	else if (m_pGameManager->Key_Down(0x45))
	{
		if (CurView == VIEW_MAP || CurView == VIEW_INVENTORY || CurView == VIEW_STATUS)
			CurView = VIEW_EQUIPMENTSLOTS;
		else
			CurView = VIEW_MAP;
		system("cls");
	}
}

void Map::Render()
{
	if (preView != CurView)
	{
		system("cls");
		preView = CurView;
	}

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
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
	case VIEW_EQUIPMENTSLOTS:
		preView = VIEW_EQUIPMENTSLOTS;
		if (Character::GetInstance()->DisplayEquipmentSlots() == true)
			CurView = VIEW_MAP;
		break;
	}

	if (preView != VIEW_EQUIPMENTSLOTS) {
		cout << "TAB : 스탯창\tE : 장비창\tI : 인벤토리\tESC : 종료" << endl;
	}

	Buffer.clear();
}

void Map::Free()
{
	Level::Free();
}

