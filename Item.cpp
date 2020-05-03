#include "Item.h"

Item::Item(string nume, pair<int, int> pos, int bonusAttack, int bonusHealth,int bonusAgility) : Entity(nume, pos)
{
	this->bonusAttack = bonusAttack;
	this->bonusHealth = bonusHealth;
	this->bonusAgility = bonusAgility;
}
Item::~Item()
{
}