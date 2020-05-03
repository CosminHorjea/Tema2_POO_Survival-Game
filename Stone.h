#pragma once
#include "Item.h"
class Stone : public Item
{
public:
	Stone(string, pair<int, int>);
	char getEntityChar() const { return 's'; };
	~Stone(){};
};