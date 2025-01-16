#pragma once
#include "Client_Defines.h"
#include "IInteractable.h"

class Portal : public IInteractable
{
public:
	Portal(int DestPosX, int DestPosY);

	virtual ~Portal();
	void Initialize();
	void SetDestination(MAP MAP_ENUM);

	void Interact() override;

protected:
	PosStruct DestPos{ 0, 0 };
	MAP Destination{ MAP_END };
};

