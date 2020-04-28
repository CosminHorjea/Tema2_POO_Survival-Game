#pragma once
#include "Entity.h"

class Agent : public Entity
{
public:
	Agent(string nume, pair<int, int> position) : Entity(nume, position){};
	pair<int, int> chooseNextPosition();
};