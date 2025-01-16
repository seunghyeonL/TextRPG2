#pragma once
#include<iostream>
#include<string>
#include<stdio.h>
#include "IItem.h"

class Shop
{
private:

public:
	Shop();
	void DisplayItemBuy(); // 상점에서 물건 구매 메뉴 출력 함수
	void DisplayItemSell(); // 상점에서 물건 판매 메뉴 출력 함수
	void ItemSell(); // 상점에서 물건을 판매하는 함수
	void ItemBuy(); // 상점에서 물건을 구매하는 함수

};