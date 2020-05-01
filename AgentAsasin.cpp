#include "AgentAsasin.h"
#include "Map.h"
pair<int, int> Asasin::chooseNextPosition(Map &m) const
{
	pair<int, int> position = this->getPosition();
	return {(position.first + 1) % 15, (position.second + 1) % 15};
}

Asasin::~Asasin() {}