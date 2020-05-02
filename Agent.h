#pragma once
#include "Entity.h"
#include "Map.h"
#include "Item.h"

class Map;
class Item;
class Agent : public Entity
{
	int attack, health;

public:
	Agent(const string nume, const pair<int, int> position, int health, int attack) : Entity(nume, position){};
	virtual pair<int, int> chooseNextPosition(Map &) const = 0;
	string getEntityType() const { return "Agent"; }
	void equipItem(Item *);
	virtual string getAgentType() = 0;
	virtual char getEntityChar() const = 0;
	virtual ~Agent() = 0;

	friend Agent *fight(Agent *, Agent *);

	friend class Item;
};