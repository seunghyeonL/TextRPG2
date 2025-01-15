#pragma once
#include "GameManager.h"
#include "IInteractable.h"
#include "Level.h"
#include <vector>
#include <utility>

class Portal : public IInteractable
{
public:
	Portal() = default;
	virtual ~Portal();
	void Initialize();
	void SetDestination(Level* Level_Dest);
	void SetPos(int Pos_X, int Pos_Y);

	void Interact() override;

protected:
	PosStruct Pos{0, 0};
	class GameManager* m_pGameManager{ nullptr };
	Level* Destination{ nullptr };

};

