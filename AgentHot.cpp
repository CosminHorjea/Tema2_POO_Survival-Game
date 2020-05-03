#include "AgentHot.h"

pair<int, int> Thief::chooseNextPosition(Map &m)
{
	vector<Entity *> around = Agent::getNearEntities(m);
	for (Entity *e : around)
	{
		if (e->getEntityType() == "Item")
		{
			return e->getPosition();
		}
	}
	return Agent::basicNextPosition(m);
}

Thief::~Thief() {}