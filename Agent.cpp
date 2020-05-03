#include "Agent.h"
#include "functii.h"
void Agent::equipItem(Item *i)
{
	this->health += i->bonusHealth;
	this->attack += i->bonusAttack;
	this->agility += i->bonusAgility;
}
Agent::~Agent()
{
}

Agent *fight(Agent *player_one, Agent *player_two)
{
	while ((player_one->health > 0) && (player_two->health > 0))
	{
		if(randInt(0,11)>player_two->agility)
			player_two->health -= player_one->attack;
		if (player_two->health <= 0)
			return player_one;
		if(randInt(0,11)>player_one->agility)
			player_one->health -= player_two->attack;
	}
	return player_two;
}