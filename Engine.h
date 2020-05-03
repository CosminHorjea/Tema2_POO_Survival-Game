#pragma once
#include "Map.h"
#include "Entity.h"
#include "Agent.h"
#include "AgentAsasin.h"
#include "AgentHot.h"
#include "AgentBrawler.h"
#include "Item.h"
#include "Medkit.h"
#include "Stone.h"
#include "Cloak.h"


class Game
{
	Map *map;
	static int roundNumber;

public:
	Game();
	void playRound();
	void printGame();
	void initializeAgents(Map &);
	void initializeItems(Map &);
	string randName();
	int randInt(int,int);
	~Game() { delete map; };
};