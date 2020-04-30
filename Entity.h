#pragma once
#include <string>
#include <utility>

using namespace std;

class Entity
{
	const string name;
	const pair<int, int> position;

public:
	Entity(const string, pair<int, int>);
	void setPosition();
	pair<int, int> getPosition() const { return this->position; };
	virtual string getEntityType() const = 0;
	virtual ~Entity() = 0;
};