#pragma once

#include "Client_Defines.h"

class MainApp final
{
private:
	MainApp();
	virtual ~MainApp() = default;

public:
	void Initialize();
	void Update();
	void Render();

private:
	void Open_Level();

	class GameManager* m_pGameManager{ nullptr };

public:
	static MainApp* Create();
	virtual void Free();
};
