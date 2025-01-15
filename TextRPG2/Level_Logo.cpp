#include "Level_Logo.h"
#include "Level_Main.h"
#include "Level_Dungeon.h"
#include "GameManager.h"
#include "Character.h"

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
		//m_pGameManager->Change_Level(new Level_Main());
		m_pGameManager->Change_Level(new Level_Dungeon());
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
	__super::Free();
}
