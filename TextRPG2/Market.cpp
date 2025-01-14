#include "Market.h"

// 상점 생성자
Market::Market()
{
	std::cout << "상점에 오신것을 환영합니다." << std::endl;
	std::cout << "원하시는 작업을 선택해주세요." << std::endl;
	gotoxy(3, 3);
	std::cout << "1번 구매하기" << std::endl;
	gotoxy(3, 4);
	std::cout << "2번 판매하기" << std::endl;
	gotoxy(3, 5);
	std::cout << "3번 나가기" << std::endl;

	int choice;
	std::cin >> choice;

	switch (choice)
	{
		case 1:
		{
			system("cls");
			DisplayItemBuy();
			break;
		}
		case 2:
		{
			system("cls");
			DisplayItemSell();
			break;
		}
		case 3:
		{
			// 마을로 복귀?? 방법을 모릅니다..
		}
	}
};

// 커서를 지정한 위치로 보내는 함수 gotoxy
void Market::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
// 아이템 구매
void Market::DisplayItemBuy()
{
	std::string space = "     ";
	std::cout << "아이템 구매" << std::endl;
	std::cout << "1번 체력 물약" << space << "20원" << std::endl;
	std::cout << "2번 공격력 버프" << space << "30원" << std::endl;
	std::cout << "3번 뒤로가기" << std::endl;
	ItemBuy();
}
void Market::ItemBuy()
{
	int Typechoice;
	std::cin >> Typechoice;

	switch (Typechoice)
	{
		case 1:
		{
			std::cout << "체력물약이(가) 구매되었습니다." << std::endl;
			std::cout << "잠시후 구매 메뉴로 돌아갑니다.";		
			Sleep(1000);
			system("cls");
			DisplayItemBuy();
		}
		case 2:
		{
			std::cout << "공격력 버프가(이) 구매되었습니다." << std::endl;
			std::cout << "잠시후 구매 메뉴로 돌아갑니다.";
			Sleep(1000);
			system("cls");
			DisplayItemBuy();
		}
		case 3:
		{
			system("cls");
			Market();
		}
	}
}

void DisplayItemSell()
{

}

void ItemSell()
{
	
}