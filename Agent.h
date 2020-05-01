#pragma once
#include "Entity.h"
#include "Map.h"

class Map;
class Agent : public Entity
{
	int attack, health;

public:
	Agent(const string nume, const pair<int, int> position) : Entity(nume, position){};
	virtual pair<int, int> chooseNextPosition(Map &) const = 0;
	string getEntityType() const { return "Agent"; }
	virtual string getAgentType() = 0;
	virtual ~Agent() = 0;
};