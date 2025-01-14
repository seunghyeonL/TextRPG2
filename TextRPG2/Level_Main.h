#pragma once

#include "Client_Defines.h"
#include "Level.h"

class Level_Main final : public Level
{
public:
	enum VIEW { VIEW_STATUS, VIEW_MAP, VIEW_END };
	enum MAP { MAP_VILLAGE, MAP_DUNGEON, MAP_SHOP, MAP_END };
private:
	Level_Main();
	virtual ~Level_Main() = default;

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	void Render_TextMap();
	void Check_Collision_Potal();
	void Correction_Map_Potal();
	void Push_Space(int i, int j);
private:
	wchar_t m_Map[MAP_HEIGHT][MAP_WIDTH];
	wstring buffer{};

	int* m_pPlayerPosX{ nullptr };
	int* m_pPlayerPosY{ nullptr };

	VIEW	m_eCurView{ VIEW_MAP };
	MAP		m_eCurMap{ MAP_VILLAGE };
public:
	static Level_Main* Create();
	virtual void Free() override;
};
