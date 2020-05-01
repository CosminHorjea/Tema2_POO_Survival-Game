#pragma once
#include "Agent.h"
#include "Map"
class Asasin : public Agent
{
public:
	Asasin(const string name, pair<int, int> position) : Agent(name, position) {}
	string getAgentType() { return "Asasin"; }
	pair<int, int> chooseNextPosition(Map &) const;
	~Asasin();
};