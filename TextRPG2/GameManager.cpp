#include <iostream>
#include "GameManager.h"
#include "HealthPotion.h"
#include "Level_Manager.h"
#include "Input_Manager.h"
#include "IMonster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Troll.h"
#include "Level.h"
#include "Orc.h"
#include <windows.h>

IMPLEMENT_SINGLETON(GameManager)

GameManager::GameManager()
{

}

void GameManager::Initialize()
{
	HINSTANCE hInstance = GetModuleHandle(nullptr);
	HWND hWnd = GetConsoleWindow();

	m_pLevel_Manager = Level_Manager::Create();

	m_pInput_Manager = Input_Manager::Create(hInstance, hWnd);
}

//IMonster* GameManager::GenerateMonster(int level)
//{
//	switch (level % 4)
//	{
//	case 0: return Slime::Create(); break;
//	case 1: return Goblin::Create(); break;
//	case 2: return Orc::Create(); break;
//	case 3: return Troll::Create(); break;
//		// case : return new BossMonster(level); break;
//	}
//}

void GameManager::VisitShop(Character* player)
{

}

void GameManager::Exit()
{


}

void GameManager::DisableEcho() {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hInput, &mode);            // 현재 콘솔 입력 모드 가져오기
	mode &= ~ENABLE_ECHO_INPUT;              // ENABLE_ECHO_INPUT 플래그 제거
	SetConsoleMode(hInput, mode);            // 수정된 모드 설정
}

void GameManager::EnableEcho() {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hInput, &mode);
	mode |= ENABLE_ECHO_INPUT; // 플래그 추가
	SetConsoleMode(hInput, mode);
}

void GameManager::Update()
{
	m_pInput_Manager->Update();

	m_pLevel_Manager->Update();
}

void GameManager::Render()
{
	m_pLevel_Manager->Render();
}

bool GameManager::KeyPressedThisFrame()
{
	return m_pInput_Manager->KeyPressedThisFrame();
}

bool GameManager::Key_Pressing(unsigned int _iKey)
{
	return m_pInput_Manager->Key_Pressing(_iKey);
}

bool GameManager::Key_Down(unsigned int _iKey)
{
	return m_pInput_Manager->Key_Down(_iKey);
}

bool GameManager::Key_Up(unsigned int _iKey)
{
	return m_pInput_Manager->Key_Up(_iKey);
}

void GameManager::Change_Level(Level* pNewLevel)
{
	if (nullptr == m_pLevel_Manager)
		return;

	m_pLevel_Manager->Change_Level(pNewLevel);
}

GameManager* GameManager::Create()
{
	GameManager* pInstance = new GameManager();

	pInstance->Initialize();

	return pInstance;
}

void GameManager::Free()
{

}
IMonster* GameManager::GenerateMonster(int level)
{
	/*if (level % 10 == 0)
	{
		cout << "보스 몬스터를 조우했습니다.\n";
		switch (level % 40)
		{
		case 0:
			Troll* troll = Troll::CreateBoss("보스 트롤", 30, 10);
			return troll;
			break;
		case 10:
			Slime* slime = Slime::CreateBoss("보스 슬라임", 30, 10);
			return slime;
			break;
		case 20:
			Goblin* goblin = Goblin::CreateBoss("보스 고블린", 30, 10);
			return goblin;
			break;
		case 30:
			Orc* orc = Orc::CreateBoss("보스 오크", 30, 10);
			return orc;
	}
	else
	{
		cout << "일반 몬스터를 조우했습니다.\n";
		switch (level % 4)
		{
		case 0:
			Troll* troll = Troll::Create("일반 트롤", 30, 10);
			return troll;
			break;
		case 1:
			Slime* slime = Slime::Create("일반 슬라임", 30, 10);
			return slime;
			break;
		case 2: 
			Goblin* goblin = Goblin::Create("일반 고블린", 30, 10);
			return goblin;
			break;
		case 3:
			Orc* orc = Orc::Create("일반 오크", 30, 10); 
			return orc;
			break;
		}
	}*/
	Orc* orc = Orc::Create("일반오크", 30, 10);
	return orc;
}

void GameManager::StartGame()
{
	string name;
	cout << "캐릭터를 생성하기 위해 이름을 입력해주세요.\n";
	getline(cin, name);
	Character* Player = Character::GetInstance(name);
	cout << "\n메뉴\n1. 스탯 창 보기     2. 전투 지역으로 이동\n";
	string choice;
	getline(cin, choice);
	switch (stoi(choice))
	{
		case 1:
			Player->DisplayStatus();
			break;
		case 2:
			Battle(Player);
			break;
		default:
			cout << "잘못된 입력입니다. 다시 시도해주세요.\n";
	}
}

void GameManager::Battle(Character* player)
{
	int level = player->GetLevel();
	IMonster* Monster = GameManager::GenerateMonster(level);
	HealthPotion* hp = new HealthPotion();
	while (true)
	{
		cout << "\n메뉴\n1. 스탯 창 보기     2. 아이템 사용     3. 전투하기     4.도망가기\n";
		int choice;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
		{

			player->DisplayStatus();
			break;
		}
		case 2:
		{
			player->Inventory.push_back(pair<IItem*, int>(hp, 1));
			player->Inventory.push_back(pair<IItem*, int>(hp, 1));
			player->DisplayInventory();
			int index;
			cin >> index;
			player->UseItem(index);

			break;
		}
		case 3:
		{
			cout << "\n전투가 시작되었습니다.\n이번에 싸울 몬스터는 " << Monster->GetName()
				<< " (체력: " << Monster->GetHealth() << ", 공격력: " << Monster->GetAttack() << ")\n";
			
			double originalAttack = player->GetAttack();  // 전투 시작 전 공격력 저장
			double increasedAttack = 0; // 공격력 증가 부분을 추적할 변수

			// 전투 진행
			while (player->GetHealth() > 0 && Monster->GetHealth() > 0) {
				cout << "\n메뉴\n1. 스탯 창 보기     2. 아이템 사용     3. 전투하기     4.도망가기\n";
				int choice;
				cin >> choice;

				switch (choice)
				{
				case 1:
					player->DisplayStatus();
					break;
				case 2:
					// 아이템 사용
					break;
				case 3:break;

				case 4:break;
				}

				// 전투 결과 처리
				if (player->GetHealth() <= 0) {
					cout << "\n전투에서 패배했습니다.\n게임 오버!\n";
					exit(0);
				}
				else {
					// 전투 승리 처리
					player->AddExperience(50);
					int gold = 10 + rand() % 10;
					player->AddGold(gold);
					cout << "\n전투에서 승리했습니다.\n50의 경험치와 " << gold << " 골드를 획득!\n";

					//IItem* DroppedItem = Monster->DropItem();
					//if (DroppedItem) {
					//	player->AddItem(DroppedItem); // 플레이어의 인벤토리에 아이템 추가
					//	cout << "몬스터가 " << DroppedItem->getName() << "을 떨어뜨렸습니다.\n";
					//}

					player->LevelUp();
					player->DisplayStatus();
				}
				Monster->Free();
			}
			break;
		}
		case 4:
		{

			break;
		}
		default:
			cout << "잘못된 입력입니다. 다시 시도해주세요.\n";
		}
	}

}
