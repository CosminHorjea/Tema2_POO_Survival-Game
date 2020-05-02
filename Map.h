#pragma once
#include "Entity.h"
#include "Agent.h"
#include "Item.h"
#include <set>
#include <vector>

class Entity;
class Agent;
class Item;
class Map
{
	vector<vector<Entity *>> entities_map;
	set<Entity *> entities;
	set<Agent *> deadAgents;
	set<Item *> itemsTaken;
	const int columns;
	const int rows;

public:
	Map(int, int);
	~Map(){};
	int getColumns() const;
	int getRows() const;
	void add_entity(Entity *);
	void remove_entity(Entity *);
	vector<Entity *> get_entities() const;
	void moveAgent(Agent *, pair<int, int>);
	void moveAgents();
	void clearMap();
	vector<Entity*> operator[](int i);
	friend ostream &operator<<(ostream &, Map &);
	friend Entity;
};