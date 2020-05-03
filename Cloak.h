#pragma once
#include "Item.h"
class Cloak : public Item
{
public:
	Cloak(string, pair<int, int>);
	char getEntityChar() const { return 'c'; };
	~Cloak(){};
};