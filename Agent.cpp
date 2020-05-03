#include "Agent.h"
#include "functii.h"
void Agent::equipItem(Item *i)
{
	this->health += i->bonusHealth;
	this->attack += i->bonusAttack;
	this->agility += i->bonusAgility;
}
Agent::~Agent()
{
}

Agent *fight(Agent *player_one, Agent *player_two)
{
	while ((player_one->health > 0) && (player_two->health > 0))
	{
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

	vector<Entity *> neighbours;
	pair<int, int> position = this->getPosition();
	int startX = (position.first - radius) < 0 ? 0 : (position.first - radius);
	int endX = (position.first + radius) >= m.getColumns() ? m.getColumns() - 1 : (position.first + radius);
	int startY = (position.second - radius) < 0 ? 0 : (position.second - radius);
	int endY = (position.second + radius) >= m.getRows() ? m.getRows() - 1 : (position.second + radius);
	// cout<<endl<<startX<<" "<<startY<<" "<<endX<<" "<<endY;
	for (int i = startY; i <= endY; i++)
	{
		for (int j = startX; j <= endX; j++)
		{
			if (m[i][j] != NULL && m[i][j] != this)
			{
				neighbours.push_back(m[i][j]);
			}
		}
	}
	return neighbours;
}

pair<int, int> Agent::basicNextPosition(Map &m)
{
	pair<int, int> position = this->getPosition();
	int ok = 0;
	while (!ok)
	{
		int nextX = position.first + possibleMoves[prefMove].first;
		int nextY = position.second + possibleMoves[prefMove].second;
		if ((nextX > 0 && nextX < m.getRows()) && (nextY > 0 && nextY < m.getColumns()))
		{
			return {nextX, nextY};
		}
		prefMove++;
		prefMove %= possibleMoves.size();
	}
}