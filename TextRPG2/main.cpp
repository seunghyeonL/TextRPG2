// 디버그
//#define _CRTDBG_MAP_ALLOC
//#include <cstdlib>
//#include <crtdbg.h>

#include "GameManager.h"
#include "MainApp.h"
#include "Character.h"
#include "EventLoop.h"
#include <locale>

void DisableCursorBlinking();
bool IsAnyKeyPressed();

int main()
{
	// 메모리 누수 확인
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::wcout.imbue(std::locale(""));
	SetConsoleOutputCP(CP_UTF8);
	DisableCursorBlinking();

	MainApp* pMainApp = MainApp::Create();

	GameManager* pGameManager = GameManager::Get_Instance();
	EventLoop* pEventLoop = EventLoop::Get_Instance();
	pGameManager->DisableEcho();

	bool bIsInit = false;
	while (true)
	{
		pMainApp->Update();
		
		pMainApp->Render();

		pEventLoop->Run();

		if (pGameManager->KeyPressedThisFrame())
			system("pause");

		if (bIsInit == false)
		{
			system("pause");
			bIsInit = true;
		}
	}

	Character* pCharacter = Character::GetInstance();

	delete pCharacter;
	pMainApp->Free();

	return 0;
}

bool IsAnyKeyPressed()
{
	for (int key = 0; key < 256; ++key)
	{
		if (GetAsyncKeyState(key) & 0x8000)
			return true;
	}
	return false;
}

void DisableCursorBlinking()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);

	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}