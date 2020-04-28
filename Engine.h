#pragma once
#include "Map.h"
class Game
{
	Map *map;
	static int roundNumber;

public:
	Game();
	void playRound();
	void printGame();
	~Game() { delete map; };
};