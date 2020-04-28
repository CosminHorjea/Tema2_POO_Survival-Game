#pragma once
#include "Entity.h"
#include "Agent.h"
#include <vector>

class Map
{
	vector<vector<Entity *>> entities_map;
	vector<Entity *> entities;
	const int columns;
	const int rows;

public:
	Map(int, int);
	~Map(){};
	int getColumns() const;
	int getRows() const;
	void add_entity(Entity *);
	vector<Entity *> get_entities() const;
	void moveAgent(Agent *, pair<int, int>);

	friend ostream &operator<<(ostream &, Map &);
};