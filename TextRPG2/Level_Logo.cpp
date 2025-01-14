#include "Level_Logo.h"
#include "Level_Main.h"
#include "GameManager.h"

Level_Logo::Level_Logo()
	: Level{}
{
}

void Level_Logo::Initialize()
{
	m_iLevelIndex = LEVEL_LOGO;

	m_strLogo = R"(

	` `   `       ` ` ``                                                              ``     ` `  `  `                       ``          ``                                  
	`   `         ` `` `                                                            ```      ` `   `                        `##`        `           `                        
	  ##` `       `##  `                                                            `##   `` `########``  ` ````````` `   `  ## `      `##########```   `#################   
	  ##` `       `##  `                                                            `##   ``### ` `` ##`  `###########`   `  ##      ```##`       ``     ```   `##` `   ```  
	  ##` `       `##  ` ``````##``     ````` `### `` ` ``##`  ``   ` ` `##```  `   `##   `  ` ``    `##           `##`   `  ##`       `##                      ##```        
	  ##` `       `##  ` #####` `###```  `####````   `###` `####   ` `##`` `###`    `##             `###         ` ##``   `  ##`        ## ``#`` ``           `####`` ``     
	  ##` `       `##  ` ### `   ``##` ` `##``` ` ` ### `` ` ``##``` `  `  `  ##`   `##             `##  `        ##`     `  ##`       `###````###` `        ###  ###`       
	  ##` `       `##  ` ##```     ##`   `##`     ``##` `````` `##   ``` `````##`   `##          ``##`         ``##`      `  ##`      ``` ``     ##``   ` `###`     ###`     
	  ##``       ``##    ##```     ##`   `##       `##############`  `####````##`   `##        ` ###``    `    ### `      `  ##`                 `##` ` ####`   ` `   `####` 
	  ###``       `##  ` ##```     ##`   `##      ` ##``         ` `###  `  ``##`   `##      ` ### ` `      `###`  `      `  ##`               ``###  ` `` `  ``##` ` ` `` ` 
	   ###``` ` ``##     ##```     ##`   `##        `###`  ``` #`   ### `   ``##`   `##    ``### ``    `  ####  `         `  ##`     `` `` ` `` ###``          `##`         `
	`   `#########`  `   ##```     ##`   `##        ` `#########   ```##########`   `##     ############`  ` `  `         `  ##`      ``#########````########################
	     `      `` `    `    `    `  ``  ``         ` ``   ``  `      ``     ```     ``   ``             `                `  ##`        `` ` ` ` ``  ``````````````````````` 
                                                                                                                                `##
)";

	m_strStart = R"(

		                                                                   Press A To Start                                                                            
)";
}

void Level_Logo::Update()
{
	/* ������ �� */
	if (m_pGameManager->Key_Down('A'))
		m_pGameManager->Change_Level(Level_Main::Create());
}

void Level_Logo::Render()
{
	system("cls");
	cout << m_strLogo;

	cout << m_strStart;
}

Level_Logo *Level_Logo::Create()
{
	Level_Logo *pInstance = new Level_Logo();

	pInstance->Initialize();

	return pInstance;
}

void Level_Logo::Free()
{
	// GameManager::StartGame 으로 Character 생성하는게 맞는데 아직 호환이 안되서
	// 이렇게 생성했어요.

	system("cls");
	m_pGameManager->EnableEcho();
	string name{};
	cout << "이름을 입력하세요: ";
	cin >> name;
	Character::GetInstance(name);
	m_pGameManager->DisableEcho();

	__super::Free();
}
