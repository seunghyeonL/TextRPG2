#pragma once
#include "Map.h"
#include "GameManager.h"

class Level_Dungeon final : public Map
{

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

public:
	Level_Dungeon();
	~Level_Dungeon() {};
	static Level_Dungeon* Create();
	virtual void Free() override;
};
