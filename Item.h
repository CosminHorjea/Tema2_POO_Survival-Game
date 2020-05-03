#pragma once
#include "Agent.h"

class Agent;

class Item : public Entity
{
	int bonusAttack, bonusHealth;

public:
	Item(string, pair<int, int>, int, int);
	string getEntityType() const { return "Item"; };
	virtual string getItemType() = 0;
	virtual char getEntityChar() const = 0;
	virtual ~Item() = 0;

	friend Agent;
};