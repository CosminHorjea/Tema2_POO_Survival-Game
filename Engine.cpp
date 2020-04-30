#include <iostream>
#include <utility>
#include "Engine.h"
#include "AgentAsasin.h"
#include "Entity.h"
#include "Agent.h"

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
	while (!done) //game loop
	{
		cout << *map;
		cout << "Doriti sa rulati o noua runda (Y)es/(N)o: ";
		/*
			TODO map.muta_agenti();
			TODO maybe mapa.drop_items();
		*/
		cin >> response;
		if (response == 'N')
			done = 1;
	}
}
void Game::initializeAgents(Map &m)
{
	for (int i = 0; i < 27; i++)
	{
		switch (i % 3)
		{
		case 1:
			m.add_entity(new Asasin("Duncan", {2, 3}));
			break;
			// case 2:
			// 	m.add_entity(new Agent);
			// case 3:
			// 	m.add_entity(new Agent);
		}
	}
}