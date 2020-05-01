#include <iostream>
#include <utility>
#include "Entity.h"
#include "Engine.h"
#include "Agent.h"

using namespace std;

Map::Map(int w, int h) : columns(w), rows(h)
{
	for (int i = 0; i < w; i++)
	{
		vector<Entity *> row;
		for (int j = 0; j < h; j++)
		{
			row.push_back(NULL);
		}
		entities_map.push_back(row);
	}
}
void Map::add_entity(Entity *e)
{
	this->entities.insert(e);
	this->entities_map[e->getPosition().first][e->getPosition().second] = e;
}
void Map::remove_entity(Entity *e)
{
	if (entities.find(e) == entities.end())
	{
		throw - 1; //TODO exceptie pt element care nu e in vector
	}
	entities_map[e->getPosition().first][e->getPosition().second] = NULL;
	entities.erase(entities.find(e));
}
void Map::moveAgent(Agent *a, pair<int, int> new_position)
{
	// if (entities_map[new_position.first][new_position.second] != NULL)
	// {
	// 	if (entities_map[new_position.first][new_position.second]->getEntityType() == "Agent")
	// 	{
	// 		//TODO beginCombat()
	// 	}
	// 	else
	// 	{
	// 		//TODO enhanceAgent()
	// 	}
	// }
	// else
	{
		entities_map[a->getPosition().first][a->getPosition().second] = NULL;
		entities_map[new_position.first][new_position.second] = a;
		a->setPosition(new_position);
	}
}
void Map::moveAgents()
{
	for (Entity *e : entities)
	{
		if (e->getEntityType() == "Agent")
		{
			Agent *aux;
			aux = dynamic_cast<Agent *>(e);
			moveAgent(aux, aux->chooseNextPosition(*this));
		}
	}
}
ostream &operator<<(ostream &out, Map &m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.columns; j++)
		{
			if (m.entities_map[i][j])
				cout << m.entities_map[i][j]->getEntityType() << " ";
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
int Map::getRows() const
{
	return this->rows;
};
int Map::getColumns() const
{
	return this->columns;
};