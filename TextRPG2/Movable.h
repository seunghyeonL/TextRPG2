#pragma once
#include "Client_Defines.h"
#include "GameManager.h"
#include "IInteractable.h"
#include "Map.h"

class Movable {
	protected:
		PosStruct CurPos{ MAP_HEIGHT / 2 , MAP_WIDTH / 2 };
	public:
		virtual ~Movable() = default;
		PosStruct GetPosition() {
			return CurPos;
		}
		void SetPosition(int PosX, int PosY) {
			CurPos.X = PosX;
			CurPos.Y = PosY;
		}
};