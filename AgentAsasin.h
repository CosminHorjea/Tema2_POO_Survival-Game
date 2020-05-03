#pragma once
#include <iostream>
#include "Agent.h"
#include "Map.h"
#include <vector>
#include <utility>

class Asasin : public Agent
{
	const vector<pair<int, int>> moves = {{2, 2}, {-2, -2}, {-2, 2}, {2, -2}}; // miscarile preferate

public:
	Asasin(const string name, pair<int, int> position) : Agent(name, position, 100, 40, 3, 2)
	{
		//un Asasin are 100- viata 40-attack 3-agilitate si 2 raza de actiune
		this->Agent::possibleMoves = moves;
	}
	pair<int, int> chooseNextPosition(Map &);
	char getEntityChar() const { return 'A'; };
	~Asasin();
};