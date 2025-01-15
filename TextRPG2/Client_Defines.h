#pragma once

#include <stdint.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

#include "Client_Macro.h"

namespace Client
{
	struct PosStruct {
		int Pos_X;
		int Pos_Y;
		bool operator==(const PosStruct& operand) {
			return Pos_X == operand.Pos_X && Pos_Y == operand.Pos_Y;
		}
	};

	enum LEVELID { LEVEL_LOGO, LEVEL_MAIN, LEVEL_END };
	
	const int MAP_WIDTH = 20; 
	const int MAP_HEIGHT = 20;

	const int MAX_HEALTH = 200;
}

using namespace std;
using namespace Client;