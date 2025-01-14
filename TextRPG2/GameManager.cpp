#include <iostream>
#include "Character.h"
#include "GameManager.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
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
	Troll* troll;
	Slime* slime;
	Goblin* goblin;
	Orc* orc;
	if (level % 10 == 0)
	{
		cout << "보스 몬스터를 조우했습니다.\n";
		switch (level % 40)
		{
		case 0:
			troll = Troll::CreateBoss("트롤 대장", level + 30, level + 10);
			return troll;
		case 10:
			slime = Slime::CreateBoss("빨간 슬라임", level + 30, level + 10);
			return slime;
		case 20:
			goblin = Goblin::CreateBoss("황금 고블린", level + 30, level + 10);
			return goblin;
		case 30:
			orc = Orc::CreateBoss("오크 족장", level + 30, level + 10);
			return orc;
		}
	}
	else
	{
		cout << "일반 몬스터를 조우했습니다.\n";
		switch (level % 4)
		{
		case 0:
			troll = Troll::Create("일반 트롤", level + 30, level + 10);
			return troll;
			break;
		case 1:
			slime = Slime::Create("일반 슬라임", level + 30, level + 10);
			return slime;
			break;
		case 2:
			goblin = Goblin::Create("일반 고블린", level + 30, level + 10);
			return goblin;
			break;
		case 3:
			orc = Orc::Create("일반 오크", level + 30, level + 10);
			return orc;
			break;
		}
	}
};

void GameManager::StartGame()
{
	srand(static_cast<unsigned int>(time(NULL)));
	string name;
	cout << "캐릭터를 생성하기 위해 이름을 입력해주세요.\n";
	getline(cin, name);
	Character* Player = Character::GetInstance(name);
	// 레벨 메인 띄우기


	/*cout << "\n메뉴\n1. 스탯 창 보기     2. 전투 지역으로 이동\n";
	string choice;
	getline(cin, choice);
	switch (stoi(choice))
	{
		case 1:
			Player->DisplayStatus();
			break;
		case 2:
			// 배틀 필드 맵 띄우기
			break;
		default:
			cout << "잘못된 입력입니다. 다시 시도해주세요.\n";
	}*/
}

void GameManager::Battle(IMonster* Monster)
{
	Character* Player = Character::GetInstance();
	HealthPotion* hp = new HealthPotion();
	AttackBoost* boost = new AttackBoost();

	// 몬스터의 위치와 캐릭터의 위치가 일치할 때
	while (Player->GetHealth() > 0 && Monster->GetHealth() > 0)
	{
		cout << "\n전투가 시작되었습니다.\n이번에 싸울 몬스터는 " << Monster->GetName()
			<< " (체력: " << Monster->GetHealth() << ", 공격력: " << Monster->GetAttack() << ")\n";

		cout << "\n메뉴\n1. 아이템 사용     2. 전투하기     3.도망가기\n";
		int choice;
		cin >> choice;

		double OriginalAttack = Player->GetAttack();  // 전투 시작 전 공격력 저장
		double IncreasedAttack = 0;
		switch (choice)
		{
		case 1:
			//Player->Inventory.push_back(pair<IItem*, int>(hp, 1));
			//Player->Inventory.push_back(pair<IItem*, int>(hp, 1));
			Player->DisplayInventory();
			if (Player->Inventory.size())
			{
				int index;
				cin >> index;
				Player->GetInven()->UseItem(index);
				double IncreasedAttack = Player->GetAttack() - OriginalAttack;
			}
		case 2:
			double originalAttack = Player->GetAttack();  // 전투 시작 전 공격력 저장
			double increasedAttack = 0; // 공격력 증가 부분을 추적할 변수
			// 전투 진행
			while (Player->GetHealth() > 0 && Monster->GetHealth() > 0) {
				cout << "\n메뉴\n1. 아이템 사용     2. 공격하기     3.도망가기\n";
				cin >> choice;
				switch (choice)
				{
				case 1:
					Player->DisplayInventory();
					if (Player->Inventory.size())
					{
						int index;
						cin >> index;
						Player->UseItem(index);
						double IncreasedAttack = Player->GetAttack() - OriginalAttack; // 공격력 증가 물약으로 증가한 공격력
					}
					break;
				case 2:
					// 플레이어의 공격
					Monster->GetDamage(Player->GetAttack());
					cout << Player->GetName() << " 플레이어가 공격했습니다.\n"
						<< Player->GetAttack() << "의 피해를 입혀 몬스터의 체력은 " << Monster->GetHealth() << "입니다.\n";

					// 몬스터의 반격
					if (Monster->GetHealth() > 0) {
						Player->SetHealth(Monster->GetAttack());
						cout << Monster->GetName() << " 몬스터가 공격했습니다.\n"
							<< Monster->GetAttack() << "의 피해를 입혀 플레이어의 체력은 " << Player->GetHealth() << "입니다.\n";
					}

					// 전투 결과 처리
					if (Player->GetHealth() <= 0) {
						cout << "\n전투에서 패배했습니다.\n게임 오버!\n";
						// cout << "1. Retry     2. Exit";
						exit(0);
					}
					else if (Monster->GetHealth() <= 0) {
						// 전투 승리 처리

						// 30퍼 확률로 아이템 드랍
						if (rand() % 100 < 30)
						{
							//IItem* DroppedItem = Monster->DropItem();
							//if (DroppedItem) {
							//	Player->AddItem(DroppedItem); // 플레이어의 인벤토리에 아이템 추가
							//	cout << "몬스터가 " << DroppedItem->GetName() << "을 떨어뜨렸습니다.\n";
							//}
						}

						Player->AddExperience(50);
						int gold = 10 + rand() % 10;
						Player->AddGold(gold);
						cout << "\n전투에서 승리했습니다.\n50의 경험치와 " << gold << " 골드를 획득!\n";

						Player->SetAttack(OriginalAttack);
						Player->LevelUp();
					}
					break;
				case 3:
					cout << Player->GetName() << " 플레이어는 도망을 선택하였습니다.\n";
					// 레벨 메인 띄우기
					break;
				}

				// 전투 결과 처리
				if (Player->GetHealth() <= 0) {
					cout << "\n전투에서 패배했습니다.\n게임 오버!\n";
					exit(0);
				}
				else {
					// 전투 승리 처리
					Player->AddExperience(50);
					int gold = 10 + rand() % 10;
					Player->GetInven()->AddGold(gold);
					cout << "\n전투에서 승리했습니다.\n50의 경험치와 " << gold << " 골드를 획득!\n";

					//IItem* DroppedItem = Monster->DropItem();
					//if (DroppedItem) {
					//	player->AddItem(DroppedItem); // 플레이어의 인벤토리에 아이템 추가
					//	cout << "몬스터가 " << DroppedItem->getName() << "을 떨어뜨렸습니다.\n";
					//}

					Player->LevelUp();
					Player->DisplayStatus();
				}
				Monster->Free();
			}
			break;
		case 3:
			cout << Player->GetName() << " 플레이어는 도망을 선택하였습니다.\n";
			// 레벨 메인 띄우기
			break;
		default:
			cout << "잘못된 입력입니다. 다시 시도해주세요.\n";
		}
	}
	boost->IsAlredyUseOne = false; // 공격력 증가 물약 사용 시 체크할 변수
	delete hp;
	delete boost;
	Monster->Free();
}
