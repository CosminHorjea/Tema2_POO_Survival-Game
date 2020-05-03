#include <iostream>
#include <utility>
#include "Engine.h"

// #include "functii.h"


using namespace std;

Game::Game()
{
	int n, done = 0;
	char response;
	cout << "Introduceti marimea hartii: ";
	// cin >> n;
	n = n<15 ? 15 : n;
	n = 20;
	map = new Map(n, n);
	initializeAgents(*map);
	initializeItems(*map);
	while (!done) //game loop
	{
		cout << *map;
		cout << "Doriti sa rulati o noua runda (Y)es/(N)o: ";
		cin >> response;
		if (response == 'N'){
			done = 1;
			break;
		}
		map->moveAgents();
	}
}
void Game::initializeAgents(Map &m)
{
	for (int i = 0; i < 21; i++)
	{
		switch (i % 3)
		{
		case 1:
			m.add_entity(new Asasin(randName(), {randInt(0, m.getRows()), randInt(0, m.getColumns())}));
			break;
		case 2:
			m.add_entity(new Thief(randName(),{randInt(0, m.getRows()), randInt(0, m.getColumns())}));
			break;
		case 0:
			m.add_entity(new Brawler(randName(),{randInt(0,m.getRows()) , randInt(0,m.getColumns())}));
			break;
		}
	}
}

void Game::initializeItems(Map &m)
{
	for (int i = 0; i < 6; i++)
	{
		switch (i % 3)
		{
		case 1:
			m.add_entity(new Medkit("Medicament", {this->randInt(1, m.getRows()), this->randInt(1, m.getColumns())}));
			break;
			case 2:
				m.add_entity(new Stone("Piatra Fermecata", {this->randInt(1, m.getRows()), this->randInt(1, m.getColumns())}));
			break;
			case 3:
				m.add_entity(new Cloak("Mantia Agilitatii", {this->randInt(1, m.getRows()), this->randInt(1, m.getColumns())}));
			break;
		}
	}
}
string Game::randName(){
	std::string names[20]={"Gwen","Trent","Geoff","DJ","Heather","Justin","Duncan","Harold","Courtney","Owen","Courtney","Beth","Duncan","Justin","Lindsay","Leshawna","Izzy","Dany","Casey","Chris"};

	return(names[randInt(0,20)]);

}
int Game::randInt(int lower, int upper)
{
	return lower + rand() % (upper - lower);
}
