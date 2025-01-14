#include "Level_Main.h"
#include "Character.h"
#include "GameManager.h"

Level_Main::Level_Main()
	: Level{}
{
}

void Level_Main::Initialize()
{
	m_iLevelIndex = LEVEL_MAIN;

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			m_Map[i][j] = L'.';
		}
	}

	m_Map[0][MAP_WIDTH / 2] = L'던';
	m_Map[0][MAP_WIDTH / 2 + 1] = L'전';

	m_Map[MAP_HEIGHT / 2][0] = L'상';
	m_Map[MAP_HEIGHT / 2][1] = L'점';

	m_pPlayerPosX = m_pGameManager->GetPlayerPosX();
	m_pPlayerPosY = m_pGameManager->GetPlayerPosY();

	*m_pPlayerPosX = MAP_WIDTH / 2;
	*m_pPlayerPosY = MAP_HEIGHT / 2;
	m_Map[*m_pPlayerPosY][*m_pPlayerPosX] = L'A';
}

void Level_Main::Update()
{
	m_Map[*m_pPlayerPosY][*m_pPlayerPosX] = L'.';

	if (m_pGameManager->Key_Down(VK_LEFT))
	{
		if ((*m_pPlayerPosX) > 0)
			(*m_pPlayerPosX)--;
	}

	if (m_pGameManager->Key_Down(VK_UP))
	{
		if ((*m_pPlayerPosY) > 0)
			(*m_pPlayerPosY)--;
	}

	if (m_pGameManager->Key_Down(VK_DOWN))
	{
		if ((*m_pPlayerPosY) < MAP_HEIGHT - 1)
			(*m_pPlayerPosY)++;
	}

	if (m_pGameManager->Key_Down(VK_RIGHT))
	{
		if ((*m_pPlayerPosX) < MAP_WIDTH - 1)
			(*m_pPlayerPosX)++;

	}

	if (m_pGameManager->Key_Down(VK_TAB))
	{
		if(m_eCurView == VIEW_MAP)
			m_eCurView = VIEW_STATUS;
		else
			m_eCurView = VIEW_MAP;
		system("cls");
	}

	Check_Collision_Potal();

	m_Map[*m_pPlayerPosY][*m_pPlayerPosX] = L'A';

	Correction_Map_Potal();
}

void Level_Main::Render()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++) {
			buffer.push_back(m_Map[i][j]);

			Push_Space(i, j);
		} 
		buffer.push_back(L'\n');
	}

	gotoxy(0, 0);

	switch (m_eCurView)
	{
	case VIEW_MAP:
		Render_TextMap();
		wcout << buffer;
		break;
	case VIEW_STATUS:
		Character::GetInstance()->DisplayStatus();
		break;
	}
	
	cout << "TAB : 스탯창\tESC : 종료" << endl;
	buffer.clear();
}

void Level_Main::Render_TextMap()
{
	switch (m_eCurMap)
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

void Level_Main::Check_Collision_Potal()
{
	switch (m_eCurMap)
	{
	case MAP_VILLAGE:
	{
		/* Check Dungeon */
		if (*m_pPlayerPosY == 0 && (*m_pPlayerPosX == MAP_WIDTH / 2 || *m_pPlayerPosX == MAP_WIDTH / 2 + 1))
		{
			m_eCurMap = MAP_DUNGEON;

			/* 여기가 던전 충돌되서 맵바꾸는 곳 */
			//GameManager::Get_Instance()->Change_Level(Level_BattleFiled::Create());

			*m_pPlayerPosY = MAP_HEIGHT - 2;
		}

		/* Check Shop */
		if (*m_pPlayerPosY == MAP_HEIGHT / 2 && (*m_pPlayerPosX == 0 || *m_pPlayerPosX == 1))
		{
			m_eCurMap = MAP_SHOP;
			*m_pPlayerPosX = MAP_WIDTH - 3;
		}

		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				m_Map[i][j] = L'.';
			}
		}

		break;
	}
	case MAP_DUNGEON:
	{
		/* Check Village */
		if (*m_pPlayerPosY == MAP_HEIGHT - 1 && (*m_pPlayerPosX == MAP_WIDTH / 2 || *m_pPlayerPosX == MAP_WIDTH / 2 + 1))
		{
			m_eCurMap = MAP_VILLAGE;
			*m_pPlayerPosY = 1;
		}

		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				m_Map[i][j] = L'.';
			}
		}

		break;
	}
	case MAP_SHOP:
	{
		/* Check Village */
		if (*m_pPlayerPosY == MAP_HEIGHT / 2 && (*m_pPlayerPosX == MAP_WIDTH - 2 || *m_pPlayerPosX == MAP_WIDTH - 1))
		{
			m_eCurMap = MAP_VILLAGE;
			*m_pPlayerPosX = 2;
		}

		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				m_Map[i][j] = L'.';
			}
		}

		break;
	}
	}
}

void Level_Main::Correction_Map_Potal()
{
	switch (m_eCurMap)
	{
	case MAP_VILLAGE:
	{
		m_Map[0][MAP_WIDTH / 2] = L'던';
		m_Map[0][MAP_WIDTH / 2 + 1] = L'전';

		m_Map[MAP_HEIGHT / 2][0] = L'상';
		m_Map[MAP_HEIGHT / 2][1] = L'점';

		break;
	}
	/* 층을 나눌지는 고민 */
	case MAP_DUNGEON:
	{
		m_Map[MAP_HEIGHT - 1][MAP_WIDTH / 2] = L'마';
		m_Map[MAP_HEIGHT - 1][MAP_WIDTH / 2 + 1] = L'을';
		break;
	}
	case MAP_SHOP:
	{
		m_Map[MAP_HEIGHT / 2][MAP_WIDTH - 2] = L'마';
		m_Map[MAP_HEIGHT / 2][MAP_WIDTH - 1] = L'을';

		break;
	}
	}
}

void Level_Main::Push_Space(int i, int j)
{
	switch (m_eCurMap)
	{
	case MAP_VILLAGE:
	{
		/* Check Duegon */
		if (!(i == 0 && (j == MAP_WIDTH / 2 || j == MAP_WIDTH / 2 + 1) ||
			/* Check Shop */
			i == MAP_HEIGHT / 2 && (j == 0 || j == 1)))
			buffer.push_back(L' ');
		break;
	}
	case MAP_DUNGEON:
	{
		/* Check Village */
		if (!(i == MAP_HEIGHT - 1 && (j == MAP_WIDTH / 2 || j == MAP_WIDTH / 2 + 1)))
			buffer.push_back(L' ');
		break;
	}
	case MAP_SHOP:
	{
		/* Check Village */
		if (!(i == MAP_HEIGHT / 2 && (j == MAP_WIDTH - 1 || j == MAP_WIDTH - 2)))
			buffer.push_back(L' ');
		break;
	}
	}
}

Level_Main* Level_Main::Create()
{
	Level_Main* pInstance = new Level_Main();

	pInstance->Initialize();

	return pInstance;
}

void Level_Main::Free()
{
	__super::Free();
}
