#include "IMonster.h"

IMonster::IMonster()
{
}

void IMonster::Free()
{

}

void IMonster::Interact() {
	auto pGameManager = GameManager::Get_Instance();

	pGameManager->Battle(this);
}