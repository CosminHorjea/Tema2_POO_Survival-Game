#include <iostream>
#include <utility>
#include "Map.h"
// #include "Engine.h"
// #include "Agent.h"
// #include "Item.h"

using namespace std;

Map::Map(int w, int h) : columns(w), rows(h)
{
	/*
		@param w,h - lungimea si inaltimea hartii
	*/
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
	/*
		@param e - pointer catre entitatea de adaugat pe harta
	*/
	this->entities.insert(e);
	this->entities_map[e->getPosition().first][e->getPosition().second] = e;
}
void Map::remove_entity(Entity *e)
{
	/*
		e - pointer catre entitatea de scos din harta
	*/
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
		return; // daca agentul este in vectorul de agenti morti trebuie sa fie scos, deci nu fac nimic
	}
	Entity *location = entities_map[new_position.first][new_position.second]; //pointer catre locatia noua
	if (location != NULL)													  //daca exista ceva pe acea locatie verific ce e
	{
		if (location->getEntityType() == "Agent") // daca e un alt agent
		{
			Agent *otherAgent = dynamic_cast<Agent *>(location); // transform entitatea in agent
			if (deadAgents.find(otherAgent) == deadAgents.end()) // doar daca celalat agent nu e mort
			{

				Agent *winner = fight(a, otherAgent); // incep combatul
				if (winner == a)					  // daca caracterul meu castiga
				{
					deadAgents.insert(otherAgent); // celalalt agent e marcat ca sa fie scos
					cout << endl
						 << "Agentul " << otherAgent->getName() << " a murit!";
				}
				else
				{
					deadAgents.insert(a);												  // altfel agentul actual trebuie sa moara
					entities_map[a->getPosition().first][a->getPosition().second] = NULL; //eliberez pozitia de pe mapa
					cout << endl
						 << "Agentul " << a->getName() << " a murit!";
					return; // nu vreau sa-l mai mut daca pierde
				}
			}
		}
		else
		{ //daca e un item
			Item *foundItem = dynamic_cast<Item *>(location);
			a->equipItem(foundItem); // il equipez
			entities_map[foundItem->getPosition().first][foundItem->getPosition().second] = NULL;
			itemsTaken.insert(foundItem);
			cout << endl
				 << a->getName() << "A luat itemul " << foundItem->getName();
		}
	}
	entities_map[new_position.first][new_position.second] = a;			  // mut agentul meu
	entities_map[a->getPosition().first][a->getPosition().second] = NULL; // marchez fosta pozitie cu null
	a->setPosition(new_position);										  // schimb pozitia agentului
	cout << endl
		 << a->getName() << " s-a mutat pe " << new_position.first << " " << new_position.second;
}
void Map::moveAgents()
{
	/*
		@params none
		Muta toti agentii
	*/
	for (Entity *e : entities) //pentru fiecare entitate
	{
		if (e->getEntityType() == "Agent") //daca e agent
		{
			Agent *aux;
			aux = dynamic_cast<Agent *>(e);
			moveAgent(aux, aux->chooseNextPosition(*this)); //apelez functia de mutare pentru agentul respectiv
		}
	}
	//sterg agentii morti si itemele luate din vector
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
	//eliberez vectorii
	deadAgents.clear();
	itemsTaken.clear();
	//refac mapa
	this->clearMap();
	for (Entity *e : entities)
	{
		this->add_entity(e);
	}
}

void Map::clearMap()
{
	/*
		@param none
		Metoda asta sterge mapa si o umple cu NULL
	*/
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

vector<Entity *> Map::operator[](int i) const
{
	/*
		@param int i - indexul randului din mapa

		@return vectorul de pe randul i din mapa
	*/
	return entities_map[i];
}

ostream &operator<<(ostream &out, Map &m)
{
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
int Map::getNoOfAliveAgents() const
{
	/*
		@returns numarul de agenti ramasi in joc
	*/
	int numberAliveAgents = 0;
	for (Entity *e : entities)
	{									   // merg prin toate entitatiile
		if (e->getEntityType() == "Agent") // daca e agent incrementez numarul
		{
			numberAliveAgents++;
		}
	}
	return numberAliveAgents;
}
int Map::getRows() const
{
	return this->rows;
};
int Map::getColumns() const
{
	return this->columns;
};

Map::~Map()
{
	this->clearMap();
	for (Entity *e : entities)
	{
		delete e;
	}
}