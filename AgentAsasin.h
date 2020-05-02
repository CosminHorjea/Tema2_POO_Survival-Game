#pragma once
#include "Agent.h"
#include "Map.h"
class Asasin : public Agent
{
public:
	Asasin(const string name, pair<int, int> position) : Agent(name, position, 50, 100) {}
	string getAgentType() { return "Asasin"; }
	pair<int, int> chooseNextPosition(Map &) const;
	char getEntityChar() const { return 'A'; };
	~Asasin();
};