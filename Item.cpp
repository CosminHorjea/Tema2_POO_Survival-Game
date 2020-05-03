#include "Item.h"

Item::Item(string nume, pair<int, int> pos, int bonusAttack, int bonusHealth, int bonusAgility) : Entity(nume, pos)
{
	// initializez clasa de baza si statusurile itemului
	this->bonusAttack = bonusAttack;
	this->bonusHealth = bonusHealth;
	this->bonusAgility = bonusAgility;
}
Item::~Item()
{
}