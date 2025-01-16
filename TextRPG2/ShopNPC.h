#pragma once
#include "Client_Defines.h"
#include "IInteractable.h"

class ShopNPC : public IInteractable
	{
	public:
		ShopNPC(int DestPosX, int DestPosY);

		virtual ~ShopNPC();
		void Initialize();

		void Interact() override;

	protected:

};

