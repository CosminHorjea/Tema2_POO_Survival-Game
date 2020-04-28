#include <iostream>
#include "Engine.h"

using namespace std;

Game::Game()
{
	int n;
	cout << "Introduceti marimea hartii: ";
	cin >> n;
	map = new Map(n, n);
	cout << *map;
}