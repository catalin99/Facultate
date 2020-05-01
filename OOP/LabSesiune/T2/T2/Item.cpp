#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	name = "Nume nesetat";
}


Item::~Item()
{
}

string Item::getName()
{
	return name;
}

void Item::setName(string NAME)
{
	name = NAME;
}
