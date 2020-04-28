#include <iostream>
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

ostream &operator<<(ostream &out, Map &m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.columns; j++)
		{
			if (m.entities_map[i][j])
				cout << m.entities_map[i][j] << " ";
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}