#pragma once
#include "Agent.h"

class Agent;

class Item : public Entity
{
	int bonusAttack, bonusHealth, bonusAgility;

public:
	Item(string, pair<int, int>, int, int, int);
	string getEntityType() const { return "Item"; };
	virtual char getEntityChar() const = 0; // caracterul reprezentativ pentru fiecare entitate
	virtual ~Item() = 0;

	friend Agent;
};