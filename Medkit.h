#pragma once
#include "Item.h"
class Medkit : public Item
{
public:
	Medkit(string, pair<int, int>);
	string getItemType() { return "MedKit"; }
	~Medkit(){};
};