#include <iostream>
#include <utility>
#include "Engine.h"

// #include "functii.h"

using namespace std;

Game::Game()
{
	int n, done = 0, ROUND = 0;
	char response;
	cout << "Introduceti marimea hartii: ";
	cin >> n;
	n = n < 15 ? 15 : n;	//daca dimensiunea introdusa este mai mica deacat 15, o setez la 15
	map = new Map(n, n);	//creez mapa
	initializeAgents(*map); //initializez agentii pe harta
	initializeItems(*map);	//initializez itemele pe harta
	while (!done)			//game loop
	{
		cout << "\nRunda: " << ROUND << endl;
		cout << *map;						//afisez stadiul hartii
		if (map->getNoOfAliveAgents() == 1) //daca a ramas doar un agent jocul se termina
		{
			cout << endl
				 << "Game OVER!" << endl;
			break;
		}
		cout << "Doriti sa rulati o noua runda (Y)es/(N)o: ";
		cin >> response;
		if (response == 'N')
		{
			done = 1;
			break;
		}
		map->moveAgents(); //mut agentii pe harta
		ROUND++;
	}
}
void Game::initializeAgents(Map &m)
{
	for (int i = 0; i < 21; i++) //pun 21 de agenti pe harta
	{
		pair<int, int> randPosition = {randInt(0, m.getRows()), randInt(0, m.getColumns())};
		while (m[randPosition.first][randPosition.second] != NULL) //iau o pozitie care nu e folosita in harta mea
		{
			randPosition = {randInt(0, m.getRows()), randInt(0, m.getColumns())};
		}
		switch (i % 3) //adaug un agent in functie de restul lui i la 3
		{
		case 1:
			m.add_entity(new Asasin(randName(), randPosition));
			break;
		case 2:
			m.add_entity(new Thief(randName(), randPosition));
			break;
		case 0:
			m.add_entity(new Brawler(randName(), randPosition));
			break;
		}
	}
}

void Game::initializeItems(Map &m)
{
	for (int i = 0; i < 6; i++) // adaug 6 obiecte
	{
		pair<int, int> randPosition = {randInt(0, m.getRows()), randInt(0, m.getColumns())};
		while (m[randPosition.first][randPosition.second] != NULL)
		{
			randPosition = {randInt(0, m.getRows()), randInt(0, m.getColumns())};
		}
		switch (i % 3)
		{
		case 1:
			m.add_entity(new Medkit("Medicament", randPosition));
			break;
		case 2:
			m.add_entity(new Stone("Piatra Fermecata", randPosition));
			break;
		case 0:
			m.add_entity(new Cloak("Mantia Agilitatii", randPosition));
			break;
		}
	}
}
//Functiile urmatoare sunt redefinite intr-un fisier functii.h, doar ca daca il includeam aici aveam o eroare pe care nu am putut sa o rezolv
string Game::randName()
{
	std::string names[20] = {"Gwen", "Trent", "Geoff", "DJ", "Heather", "Justin", "Duncan", "Harold", "Courtney", "Owen", "Courtney", "Beth", "Duncan", "Justin", "Lindsay", "Leshawna", "Izzy", "Dany", "Casey", "Chris"};

	return (names[randInt(0, 20)]);
}
int Game::randInt(int lower, int upper)
{
	return lower + rand() % (upper - lower);
}
