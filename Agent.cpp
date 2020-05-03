#include "Agent.h"
#include "functii.h"
void Agent::equipItem(Item *i)
{
	/*
		@param i - pointer catre itemul dorit

		incrementez statusurile agentului cu statusurile obiectului
	*/
	this->health += i->bonusHealth;
	this->attack += i->bonusAttack;
	this->agility += i->bonusAgility;
}
Agent::~Agent()
{
}

Agent *fight(Agent *player_one, Agent *player_two)
{
	/*
		@param player_one,player_two - cei doi agenti care intra in conflict

		@returns Agent* - adresa agentului castigator
	*/
	while ((player_one->health > 0) && (player_two->health > 0)) // cat timp ambii au viata pozitiva
	{
		//daca valoare random e mai mare decat agilitatea agentului, atunci agentul lovesc
		// altfel agentul rateaza
		if (randInt(0, 11) > player_two->agility)
			player_two->health -= player_one->attack;
		if (player_two->health <= 0)
			return player_one;
		if (randInt(0, 11) > player_one->agility)
			player_one->health -= player_two->attack;
	}
	return player_two;
}
vector<Entity *> Agent::getNearEntities(Map &m) const
{
	/*
		@param Map m - mapa pe care se executa mutarea

		@return vector<Entity*> - un vector cu toate entitatile din campul vizual al agentului
	*/

	vector<Entity *> neighbours;				   // vectorul returnat
	pair<int, int> position = this->getPosition(); //pozitia centrala
	//calculez toate coordonatele pentru iteratie
	int startX = (position.first - radius) < 0 ? 0 : (position.first - radius);
	int endX = (position.first + radius) >= m.getColumns() ? m.getColumns() - 1 : (position.first + radius);
	int startY = (position.second - radius) < 0 ? 0 : (position.second - radius);
	int endY = (position.second + radius) >= m.getRows() ? m.getRows() - 1 : (position.second + radius);
	for (int i = startY; i <= endY; i++)
	{
		for (int j = startX; j <= endX; j++)
		{
			if (m[i][j] != NULL && m[i][j] != this) //daca pozitia din harta contine o entitate care nu este agentul in sine
			{
				neighbours.push_back(m[i][j]); // o adaug in vector
			}
		}
	}
	return neighbours; // retuenz "vecinii" agentului
}

pair<int, int> Agent::basicNextPosition(Map &m)
{
	/*
		@param m - mapa pe care se face mutarea

		@return mutarea valida pentru agent, aleasa dintr-un vector de mutari preferate
	*/
	pair<int, int> position = this->getPosition();
	int ok = 0; // presupun ca pozitia pe care o aleg nu e ok
	while (!ok)
	{
		int nextX = position.first + possibleMoves[prefMove].first;
		int nextY = position.second + possibleMoves[prefMove].second;
		if ((nextX > 0 && nextX < m.getRows()) && (nextY > 0 && nextY < m.getColumns())) // daca se afla pe harta
		{
			return {nextX, nextY}; // o returnez
		}
		prefMove++;						  // altfel trec la urmatorul index in vecotrul de miscari ale agentulu
		prefMove %= possibleMoves.size(); // ma sigur ca nu ies din lungimea vectorului
	}
}