#pragma once
#include "Map.h"
#include "GameManager.h"

class Level_Dungeon final : public Map
{

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
private:
	VIEW preView{ VIEW_MAP };
public:
	Level_Dungeon();
	~Level_Dungeon() {};
	virtual void Free() override;
};
