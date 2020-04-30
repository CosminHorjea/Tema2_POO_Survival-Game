#pragma once
#include "Entity.h"

class Agent : public Entity
{
public:
	Agent(const string nume, const pair<int, int> position) : Entity(nume, position){};
	pair<int, int> chooseNextPosition();
	string getEntityType() const { return "Agent"; }
	virtual string getAgentType() = 0;
	virtual ~Agent() = 0;
};