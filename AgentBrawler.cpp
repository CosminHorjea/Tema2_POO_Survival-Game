#include "AgentBrawler.h"

pair<int, int> Brawler::chooseNextPosition(Map &m)
{
	// un brawler prioritizeaza agentii dar ia in considerare si itemele
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