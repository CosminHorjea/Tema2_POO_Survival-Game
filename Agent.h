#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Map.h"
#include "Item.h"

using namespace std;

class Map;
class Item;
class Agent : public Entity
{
	int attack, health, agility;

protected:
	vector<pair<int, int>> possibleMoves;
	int radius, prefMove = 0;

public:
	Agent(const string nume, const pair<int, int> position, int health, int attack, int agility, int radius) : Entity(nume, position)
	{
		this->attack = attack;
		this->health = health;
		this->agility = agility;
		this->radius = radius;
	};
	virtual pair<int, int> chooseNextPosition(Map &) = 0;
	string getEntityType() const { return "Agent"; }
	void equipItem(Item *);
	vector<Entity *> getNearEntities(Map &);
	pair<int, int> basicNextPosition(Map &);
	virtual string getAgentType() = 0;
	virtual char getEntityChar() const = 0;
	virtual ~Agent() = 0;

	friend Agent *fight(Agent *, Agent *);

	friend class Item;
};