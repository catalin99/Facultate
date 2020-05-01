#pragma once
#include "Item.h"
class ShoppingList
{
	list<Item*> L;
public:
	ShoppingList();
	~ShoppingList();
	void addItem(Item* i);
	void printList();
};

