#pragma once
#include "Map.h"
#include "Entity.h"
#include "Agent.h"
#include "AgentAsasin.h"
#include "AgentHot.h"
#include "Item.h"
#include "Medkit.h"
#include "functii.h"


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
	~Game() { delete map; };
};