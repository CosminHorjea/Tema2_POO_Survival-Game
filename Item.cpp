#include "Item.h"

Item::Item(string nume, pair<int, int> pos, int bonusAttack, int bonusHealth) : Entity(nume, pos)
{
	this->bonusAttack = bonusAttack;
	this->bonusHealth = bonusHealth;
}
Item::~Item()
{
}