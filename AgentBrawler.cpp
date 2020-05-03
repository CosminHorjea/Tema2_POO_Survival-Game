#include "AgentBrawler.h"

pair<int, int> Brawler::chooseNextPosition(Map &m)
{
	vector<Entity *> around = Agent::getNearEntities(m);
	for (Entity *e : around)
	{
		if (e->getEntityType() == "Agent")
		{
			return e->getPosition();
		}
	}
	for (Entity *e : around)
	{
		if (e->getEntityType() == "Item")
		{
			return e->getPosition();
		}
	}
	return Agent::basicNextPosition(m);
}

Brawler::~Brawler() {}