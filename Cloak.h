#pragma once
#include "Item.h"
class Cloak : public Item
{
public:
	Cloak(string, pair<int, int>);
	string getItemType() { return "Cloak of Agility"; }
	char getEntityChar() const { return 'c'; };
	~Cloak(){};
};