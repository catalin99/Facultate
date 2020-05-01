#include "stdafx.h"
#include "ShoppingList.h"


ShoppingList::ShoppingList()
{
}


ShoppingList::~ShoppingList()
{
}

void ShoppingList::addItem(Item * i)
{
	L.push_back(i);
}

void ShoppingList::printList()
{
	for (auto i : L)
	{
		//printf("%s : %s; ", i->getName(), i->getInfo());
		cout << i->getName() << " : " << i->getInfo() << "; ";
	}
}
