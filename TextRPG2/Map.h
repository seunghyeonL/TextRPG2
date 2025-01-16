#pragma once

#include "Client_Defines.h"
#include "Level.h"
#include "IInteractable.h"
#include <unordered_map>
#include <utility>

class Map : public Level
{
protected:
	Map() {};
	virtual ~Map() = default;

	MAP MapType{MAP_VILLAGE};
	VIEW CurView{VIEW_MAP};

	vector<IInteractable *> Interactables;

	unordered_map<PosStruct, pair<string, IInteractable *>, PosStructHash> m_Map;
	string Buffer{};

	void gotoxy(int x, int y);
	void Render_TextMap();

public:
	virtual void Initialize() override = 0;
	virtual void Update() override = 0;
	virtual void Render() override = 0;

	// IInteractable* GetObjOfMap(int Pos_X, int Pos_Y) const {
	//	return m_Map.at(PosStruct{ Pos_X, Pos_Y }).second;
	// };

	virtual void Free() override;
};