#include <iostream>
#include "Entity.h"

Entity::Entity(const string nume, const pair<int, int> pozitie) : name(nume), position(pozitie){};

string Entity::getName(){
	return this->name;
}

Entity::~Entity()
{
}