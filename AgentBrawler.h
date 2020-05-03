#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Agent.h"

class Brawler : public Agent
{
	const vector<pair<int, int>> moves = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
	int prefferedMove=0;

public:
	Brawler(const string name, pair<int, int> position) : Agent(name, position, 200, 30, 0, 1)
	{
		this->Agent::possibleMoves = moves;
	}
	string getAgentType() { return "Brawler"; }
	pair<int, int> chooseNextPosition(Map &) ;
	char getEntityChar() const { return 'B'; };
	~Brawler();
};