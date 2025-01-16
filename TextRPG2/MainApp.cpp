#include "MainApp.h"
#include "GameManager.h"
#include "Level_Logo.h"

MainApp::MainApp()
{

}

void MainApp::Initialize()
{
	m_pGameManager = GameManager::Get_Instance();

	m_pGameManager->Initialize();

	Open_Level();
}

void MainApp::Update()
{
	m_pGameManager->Update();
}

void MainApp::Render()
{
	m_pGameManager->Render();
}

void MainApp::Open_Level()
{
	m_pGameManager->Change_Level(Level_Logo::Create());
}

MainApp* MainApp::Create()
{
	MainApp* pInstance = new MainApp();

	pInstance->Initialize();


	return pInstance;
}

void MainApp::Free()
{
	m_pGameManager->Free();
	delete this;
}
