#include "Map.h"

void Map::gotoxy(int x, int y) {
	COORD coord;
	coord.X = SHORT(x);
	coord.Y = SHORT(y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Map::Render_TextMap()
{
	switch (MapType)
	{
	case MAP_VILLAGE:
		cout << "MAP : 마을" << endl;
		break;
	case MAP_DUNGEON:
		cout << "MAP : 던전" << endl;
		break;
	case MAP_SHOP:
		cout << "MAP : 상점" << endl;
		break;
	}
}

void Map::Free()
{
	for (auto el : Interactables) {
		delete el;
	}
	Level::Free();
}

