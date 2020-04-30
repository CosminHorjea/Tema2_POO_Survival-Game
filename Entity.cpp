#include "Entity.h"
#include <iostream>
#include <utility>

Entity::Entity(const string nume, const pair<int, int> pozitie) : name(nume), position(pozitie){};

Entity::~Entity()
{
}