#pragma once

#include <stdint.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

#include "Client_Macro.h"

namespace Client
{
	enum LEVELID { LEVEL_LOGO, LEVEL_MAIN, LEVEL_END };
	
	const int MAP_WIDTH = 20; 
	const int MAP_HEIGHT = 20;

}

using namespace std;
using namespace Client;