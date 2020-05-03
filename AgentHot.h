#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Agent.h"

class Thief : public Agent
{
	const vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //miscarile preferate

public:
	Thief(const string name, pair<int, int> position) : Agent(name, position, 130, 20, 1, 1)
	{
		// Un Hot are 130 viata, 20 attack 1 agilitate si 1 raza de actiune
		this->Agent::possibleMoves = moves;
	}
	pair<int, int> chooseNextPosition(Map &);
	char getEntityChar() const { return 'T'; };
	~Thief();
};