#pragma once

#include "Client_Defines.h"
#include "Level.h"

class Level_Logo final : public Level
{
private:
	Level_Logo();
	virtual ~Level_Logo() = default;

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	string m_strLogo;
	string m_strStart;

	int m_iPlayerPosX{ 0 };
	int m_iPlayerPosY{ 0 };
public:
	static Level_Logo* Create();
	virtual void Free() override;
};
