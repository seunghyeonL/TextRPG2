#pragma once

#include<iostream>
#include<string>
#include<Windows.h>
#include<stdio.h>

class Market
{
private:

public:
	Market(); // 상점 생성자
	void gotoxy(int x, int y); // 콘솔창에서 커서를 지정한 위치로 보내는 함수
	void DisplayItemBuy(); // 상점에서 물건 구매 메뉴 출력 함수
	void DisplayItemSell(); // 상점에서 물건 판매 메뉴 출력 함수
	void ItemSell(); // 상점에서 물건을 판매하는 함수
	void ItemBuy(); // 상점에서 물건을 구매하는 함수
	
};

/*
상점 입장

입장 안내메시지 후
구입, 판매, 나가기 선택화면
구입 선택 시 
 - 물품 목록 + 수량 나오기 
 - 물품 선택 및 구매하기 선택
 - 상점 수량 감소 및 캐릭터 인벤토리 수량 증가 및 캐릭터 골드 감소 
 
 판매 선택 시 - ?? 도움..필요..
 - 보유 물품 + 수량 나오기 
 - 물품 선택 및 판매하기 선택 
 - 캐릭터 인벤토리 수량 감소 및 캐릭터 골드 증가
 
 나가기 선택 시 - ?? 모릅디다..
 상점 화면 종료 및 메인 맵으로 복귀
  */