#pragma once
#include "Item.h"
class Stone : public Item
{
public:
	Stone(string, pair<int, int>);
	string getItemType() { return "Magic Stone"; }
	char getEntityChar() const { return 's'; };
	~Stone(){};
};