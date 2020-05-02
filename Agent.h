#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Entity.h"
#include "Map.h"
#include "Item.h"

using namespace std;

class Map;
class Item;
class Agent : public Entity
{
	int attack, health, agility, radius;
	vector<pair<int, int>> possibleMoves;

public:
	Agent(const string nume, const pair<int, int> position, int health, int attack, int agility, int radius, const vector<pair<int, int>> *posMoves) : Entity(nume, position)
	{
		this->attack = attack;
		this->health = health;
		this->agility = agility;
		this->radius = radius;
		std::cout << "Maybe here\n";
		// cout << posMoves[1].first;
		this->possibleMoves.assign(posMoves->begin(), posMoves->end());
		// std::cout << "Maybe here\n";
	};
	virtual pair<int, int> chooseNextPosition(Map &) const = 0;
	string getEntityType() const { return "Agent"; }
	void equipItem(Item *);
	virtual string getAgentType() = 0;
	virtual char getEntityChar() const = 0;
	virtual ~Agent() = 0;

	friend Agent *fight(Agent *, Agent *);

	friend class Item;
};