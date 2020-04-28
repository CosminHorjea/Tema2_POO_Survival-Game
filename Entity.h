#pragma once
#include <string>
#include <utility>

using namespace std;

class Entity
{
	string name;
	pair<int, int> position;

public:
	Entity(string, pair<int, int>);
	void setPosition();
	void getPosition();
	virtual string getEntityType() const = 0;
	virtual ~Entity(){};
};