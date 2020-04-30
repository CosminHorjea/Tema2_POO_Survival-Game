#pragma once
#include "Agent.h"
class Asasin : public Agent
{
public:
	Asasin(const string name, pair<int, int> position) : Agent(name, position) {}
	string getAgentType() { return "Asasin"; }
	~Asasin();
};