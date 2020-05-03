#pragma once
#include "Item.h"
class Medkit : public Item
{
public:
	Medkit(string, pair<int, int>);
	char getEntityChar() const { return 'm'; };
	~Medkit(){};
};