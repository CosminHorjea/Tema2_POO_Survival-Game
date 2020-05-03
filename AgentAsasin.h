#pragma once
#include <iostream>
#include "Agent.h"
#include "Map.h"
#include <vector>
#include <utility>

class Asasin : public Agent
{
	const vector<pair<int, int>> moves = {{2, 2}, {-2, -2}, {-2, 2}, {2, -2}};

public:
	Asasin(const string name, pair<int, int> position) : Agent(name, position, 100, 30, 3, 2)
	{
		this->Agent::possibleMoves = moves;
	}
	string getAgentType() { return "Asasin"; }
	pair<int, int> chooseNextPosition(Map &);
	char getEntityChar() const { return 'A'; };
	~Asasin();
};