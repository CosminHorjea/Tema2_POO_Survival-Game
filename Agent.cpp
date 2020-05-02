#include "Agent.h"
#include "Entity.h"
#include "Map.h"
#include "Item.h"

void Agent::equipItem(Item *i)
{
	this->health += i->bonusHealth;
	this->attack += i->bonusAttack;
}
Agent::~Agent()
{
}

Agent *fight(Agent *player_one, Agent *player_two)
{
	while ((player_one->health > 0) && (player_two->health > 0))
	{
		player_two->health -= player_one->attack;
		if (player_two->health <= 0)
			return player_one;
		player_one->health -= player_two->attack;
	}
	return player_two;
}