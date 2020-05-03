#include "AgentAsasin.h"
// #include "Map.h"
pair<int, int> Asasin::chooseNextPosition(Map &m)
{

	vector<Entity *> around = Agent::getNearEntities(m);
	for (Entity *e : around)
	{
		if (e->getEntityType() == "Agent")
		{
			return e->getPosition();
		}
	}
	return Agent::basicNextPosition(m);
}

Asasin::~Asasin() {}