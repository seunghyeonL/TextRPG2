#include "Level_Main.h"
#include "Level_Dungeon.h"
#include "Level_Shop.h"
#include "Portal.h"
#include "Character.h"

Level_Dungeon::Level_Dungeon()
	: Map{}
{
	Initialize();
}
void Level_Dungeon::Initialize()
{
	MapType = MAP_VILLAGE;

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			m_Map.insert({ PosStruct{ i, j }, { ". ", nullptr} });
		}
	}

	Character* character = Character::GetInstance();

	PosStruct cPos = character->GetPosition();

	m_Map[cPos] = { "A ", nullptr };
}

void Level_Dungeon::Update() {
	auto character = Character::GetInstance();
	PosStruct CurPos = character->GetPosition();

	if (m_pGameManager->Key_Down(VK_LEFT))
	{
		if (CurPos.X > 0) {
			auto Interactable = m_Map[PosStruct{ CurPos.X - 1, CurPos.Y }].second;
			if (Interactable) {
				Interactable->Interact();
			}
			else {
				CurPos.X--;
				character->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_UP))
	{
		if (CurPos.Y > 0) {
			auto Interactable = m_Map[PosStruct{ CurPos.X, CurPos.Y - 1 }].second;
			if (Interactable) {
				Interactable->Interact();
			}
			else {
				CurPos.Y--;
				character->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_DOWN))
	{
		if (CurPos.Y < MAP_HEIGHT - 1) {
			auto Interactable = m_Map[PosStruct{ CurPos.X, CurPos.Y + 1 }].second;
			if (Interactable) {
				Interactable->Interact();
			}
			else {
				CurPos.Y++;
				character->SetPosition(CurPos.X, CurPos.Y);
			}
		}
	}
	else if (m_pGameManager->Key_Down(VK_RIGHT))
	{
		if (CurPos.X < MAP_WIDTH - 1) {
			auto Interactable = m_Map[PosStruct{ CurPos.X + 1, CurPos.Y }].second;
			if (Interactable) {
				Interactable->Interact();
			}
			else {
				CurPos.X++;
				character->SetPosition(CurPos.X, CurPos.Y);
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
}

void Level_Dungeon::Render()
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

void Level_Dungeon::Free()
{
	Map::Free();
}
