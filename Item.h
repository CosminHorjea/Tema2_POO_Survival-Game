#pragma once
#include "Entity.h"

class Item : public Entity
{
public:
	virtual string getItemType();
};