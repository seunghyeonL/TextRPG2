#pragma once
#include "IInteractable.h"
#include "Level.h"

class Portal : public IInteractable
{
public:
	Portal(int PosX, int PosY, int DestPosX, int DestPosY);

	virtual ~Portal();
	void Initialize();
	void SetDestination(Level* Level_Dest);

	void Interact() override;

	PosStruct GetPos() {
		return Pos;
	};

protected:
	PosStruct Pos{ 0, 0 };
	PosStruct DestPos{ 0, 0 };
	Level* Destination{ nullptr };
};

