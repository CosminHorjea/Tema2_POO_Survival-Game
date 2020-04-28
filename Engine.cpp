#include <iostream>
#include "Engine.h"

using namespace std;

Game::Game()
{
	int n, done = 0;
	char response;
	cout << "Introduceti marimea hartii: ";
	cin >> n;
	map = new Map(n, n);
	//TODO:
	//		-> map.place items()
	//      -> map.place Agents()
	while (!done) //game loop
	{
		cout << *map;
		cout << "Doriti sa rulati o noua runda (Y)es/(N)o: ";
		//TODO map.muta_agenti();
		//TODO maybe mapa.drop_items();
		cin >> response;
		if (response == 'N')
			done = 1;
	}
}