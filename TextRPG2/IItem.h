#pragma once

#include <iostream>
#include <string>

using namespace std;

class Character;
class Inventory;

class IItem abstract
{
public:
	virtual ~IItem() = default;
	virtual string GetName() = 0;
	virtual void AddToInventory(shared_ptr<Inventory> inventory, int quantity) = 0;
	virtual void RemoveToInventory(shared_ptr<Inventory> inventory, int quantity) = 0;
};