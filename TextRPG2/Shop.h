#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "IEquipmentItem.h"
#include "IConsumptionItem.h"
#include "IEtcItem.h"

class Shop
{
private:
	static Shop* Instance;
	Shop();
	Shop(const Shop&) = delete;
	Shop& operator=(const Shop&) = delete;
	vector<IEquipmentItem*> EquipItem;
	vector<pair<IConsumptionItem*, int>> ConsumptionItem;
	vector<pair<IEtcItem*, int>> OtherItem;
public:
	static Shop *GetInstance();
	void OnSaleItem();
	vector<IEquipmentItem*> GetEquipList();
	vector<pair<IConsumptionItem*, int>> GetConsumptionList();
	vector<pair<IEtcItem*, int>> GetOtherList();
};