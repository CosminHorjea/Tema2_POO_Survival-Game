#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Agent.h"

class Brawler : public Agent
{
	const vector<pair<int, int>> moves = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

public:
	Brawler(const string name, pair<int, int> position) : Agent(name, position, 200, 30, 0, 1)
	{
		// un Brawler are 200-viata; 20-attack, 0- agilitate si 1- raza de actiune
		this->Agent::possibleMoves = moves;
	}
	pair<int, int> chooseNextPosition(Map &);
	char getEntityChar() const { return 'B'; };
	~Brawler();
};