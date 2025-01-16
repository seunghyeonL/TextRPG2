#pragma once
#include "Map.h"
#include "GameManager.h"

class Level_Main final : public Map
{

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
private:
	VIEW preView{ VIEW_MAP };
public:
	Level_Main();
	~Level_Main() {};
	virtual void Free() override;
};
