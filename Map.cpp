#include <iostream>
#include <utility>
#include "Map.h"
// #include "Engine.h"
// #include "Agent.h"
// #include "Item.h"

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
		throw - 1;
	}
	entities_map[e->getPosition().first][e->getPosition().second] = NULL;
	entities.erase(entities.find(e));
}
void Map::moveAgent(Agent *a, pair<int, int> new_position)
{
	if (deadAgents.find(a) != deadAgents.end())
	{
		return;
	}
	Entity *location = entities_map[new_position.first][new_position.second];
	if (location != NULL)
	{
		if (location->getEntityType() == "Agent")
		{
			Agent *otherAgent = dynamic_cast<Agent *>(location);
			Agent *winner = fight(a, otherAgent);
			if (winner == a)
			{
				// entities.erase(entities.find(otherAgent));
				deadAgents.insert(otherAgent);
				cout << endl
					 << "Agentul " << otherAgent->getName() << " a murit!";
			}
			else
			{
				// entities.erase(entities.find(a));
				deadAgents.insert(a);
				entities_map[a->getPosition().first][a->getPosition().second] = NULL;
				cout << endl
					 << "Agentul " << a->getName() << " a murit!";
				return; // nu vreau sa-l mai mut daca pierde
			}
		}
		else
		{
			Item *foundItem = dynamic_cast<Item *>(location);
			a->equipItem(foundItem);
			entities_map[foundItem->getPosition().first][foundItem->getPosition().second];
			// entities.erase(entities.find(foundItem));
			itemsTaken.insert(foundItem);
			cout << endl
				 << a->getName() << "A luat itemul " << foundItem->getName();
		}
	}
	entities_map[a->getPosition().first][a->getPosition().second] = NULL;
	entities_map[new_position.first][new_position.second] = a;
	a->setPosition(new_position);
	cout << endl
		 << a->getName() << " s-a mutat pe " << new_position.first << " " << new_position.second;
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
	for (Agent *a : deadAgents)
	{
		entities.erase(a);
		delete a;
	}
	for (Item *i : itemsTaken)
	{
		entities.erase(i);
		delete i;
	}
	deadAgents.clear();
	itemsTaken.clear();
	this->clearMap();
	for (Entity *e : entities)
	{
		this->add_entity(e);
	}
}

void Map::clearMap()
{
	entities_map.clear();
	for (int i = 0; i < columns; i++)
	{
		vector<Entity *> row;
		for (int j = 0; j < rows; j++)
		{
			row.push_back(NULL);
		}
		entities_map.push_back(row);
	}
}

vector<Entity *> Map::operator[](int i)
{
	return entities_map[i];
}

ostream &operator<<(ostream &out, Map &m)
{
	cout << m.entities.size();
	cout << endl;
	for (int i = 0; i <= m.columns + 1; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < m.rows; i++)
	{
		cout << "|";
		for (int j = 0; j < m.columns; j++)
		{
			if (m.entities_map[i][j])
				cout << m.entities_map[i][j]->getEntityChar();
			else
			{
				cout << " ";
			}
		}
		cout << "|" << endl;
	}
	for (int i = 0; i <= m.columns + 1; i++)
	{
		cout << "-";
	}
	cout << endl;
	return out;
}
int Map::getRows() const
{
	return this->rows;
};
int Map::getColumns() const
{
	return this->columns;
};