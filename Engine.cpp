#include <iostream>
#include <utility>
#include "utility.h"
#include "Engine.h"
#include "AgentAsasin.h"
#include "Entity.h"
#include "Agent.h"
#include "Item.h"
#include "Medkit.h"

using namespace std;

Game::Game()
{
	int n, done = 0;
	char response;
	cout << "Introduceti marimea hartii: ";
	// cin >> n;
	n = 15;
	map = new Map(n, n);
	initializeAgents(*map);
	//TODO:
	//		-> map.place items()
	//      -> map.place Agents()
	initializeItems(*map);
	while (!done) //game loop
	{
		cout << *map;
		cout << "Doriti sa rulati o noua runda (Y)es/(N)o: ";
		/*
			TODO map.muta_agenti();
			TODO maybe mapa.drop_items();
		*/
		map->moveAgents();
		cin >> response;
		if (response == 'N')
			done = 1;
	}
}
void Game::initializeAgents(Map &m)
{
	for (int i = 0; i < 21; i++)
	{
		switch (i % 3)
		{
		case 1:
			m.add_entity(new Asasin("Duncan", {randInt(1, m.getRows()), randInt(1, m.getColumns())}));
			break;
			// case 2:
			// 	m.add_entity(new Agent);
			// case 3:
			// 	m.add_entity(new Agent);
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
			m.add_entity(new Medkit("Medicament", {randInt(1, m.getRows()), randInt(1, m.getColumns())}));
			break;
			// case 2:
			// 	m.add_entity(new Agent);
			// case 3:
			// 	m.add_entity(new Agent);
		}
	}
}