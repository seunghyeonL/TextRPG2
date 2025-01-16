#pragma once
#include "Map.h"
#include "GameManager.h"

class Level_Shop final : public Map
{

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;


public:
	Level_Shop();
	virtual ~Level_Shop() = default;
	virtual void Free() override;
};
