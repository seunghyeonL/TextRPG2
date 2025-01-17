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

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			m_Map.insert({ PosStruct{i, j}, {". ", nullptr} });
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

void Level_Main::Update()
{
	Map::Update();
}

void Level_Main::Render()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			string Tile = m_Map[PosStruct{ i, j }].first;
			
			Buffer += m_Map[PosStruct{ i, j }].first;
		}
		Buffer.push_back(L'\n');
	}
	if (preView != CurView)
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
		cout << "TAB : 스탯창\tE : 장비창\tI : 인벤토리\tESC : 종료" << endl;
		break;
	case VIEW_STATUS:
		Character::GetInstance()->DisplayStatus();
		cout << "TAB : 스탯창\tE : 장비창\tI : 인벤토리\tESC : 종료" << endl;
		break;
	case VIEW_INVENTORY:
		Character::GetInstance()->DisplayInventory();
		cout << "TAB : 스탯창\tE : 장비창\tI : 인벤토리\tESC : 종료" << endl;
		break;
	case VIEW_EQUIPMENTSLOTS:
		preView = VIEW_EQUIPMENTSLOTS;
		if (Character::GetInstance()->DisplayEquipmentSlots() == true)
			CurView = VIEW_MAP;
		break;
	}

	Buffer.clear();
}

void Level_Main::Free()
{
	Map::Free();
}
