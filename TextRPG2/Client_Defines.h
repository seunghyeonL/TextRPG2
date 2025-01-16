#pragma once

#include <stdint.h>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

#include "Client_Macro.h"

namespace Client
{
	struct PosStruct {
		int X;
		int Y;
		bool operator==(const PosStruct& operand) const {
			return X == operand.X && Y == operand.Y;
		}
	};

	struct PosStructHash {
		std::size_t operator()(const PosStruct& pos) const {
			return std::hash<int>()(pos.X) ^ (std::hash<int>()(pos.Y) << 1);
		}
	};

	struct LasyCout {
		void operator()(std::string str) {
			for (char c : str) {
				std::cout << c;
				//Sleep(25);
			}
		}
	};

	enum LEVELID { LEVEL_LOGO, LEVEL_MAP, LEVEL_END };
	enum VIEW { VIEW_STATUS, VIEW_MAP, VIEW_INVENTORY, VIEW_SHOP, VIEW_END };
	enum MAP { MAP_VILLAGE, MAP_DUNGEON, MAP_SHOP, MAP_END };

	const int MAP_WIDTH = 20;
	const int MAP_HEIGHT = 20;

	const int MAX_HEALTH = 200;
}

using namespace std;
using namespace Client;

