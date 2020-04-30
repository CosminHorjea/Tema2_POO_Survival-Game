#include <iostream>
#include <utility>
#include "Entity.h"
#include "Engine.h"

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
	this->entities.push_back(e);
	this->entities_map[e->getPosition().first][e->getPosition().second] = e;
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
				// m.entities_map[i][j]->getEntityType();
			}
		}
		cout << endl;
	}
}