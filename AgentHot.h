#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Agent.h"

class Thief : public Agent
{
	const vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
	Thief(const string name, pair<int, int> position) : Agent(name, position, 130, 20, 1, 1)
	{
		this->Agent::possibleMoves = moves;
	}
	string getAgentType() { return "Thief"; }
	pair<int, int> chooseNextPosition(Map &);
	char getEntityChar() const { return 'T'; };
	~Thief();
};