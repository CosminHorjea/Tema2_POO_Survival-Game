#include "AgentAsasin.h"
// #include "Map.h"
pair<int, int> Asasin::chooseNextPosition(Map &m)
{
	//prioritizez ceilalti agenti din vecinatate
	vector<Entity *> around = Agent::getNearEntities(m);
	for (Entity *e : around)
	{
		if (e->getEntityType() == "Agent")
		{
			return e->getPosition();
		}
	}
	//daca nu gasesc agenti iau pozitia basic
	return Agent::basicNextPosition(m);
}

Asasin::~Asasin() {}