#pragma once
#include <string>
#include <utility>


using namespace std;

class Entity
{
	const string name;
	pair<int, int> position;

public:
	Entity(const string, pair<int, int>);
	void setPosition(pair<int, int> new_position) { this->position = new_position; };
	string getName();
	pair<int, int> getPosition() const { return this->position; };
	virtual char getEntityChar() const = 0;
	virtual string getEntityType() const = 0;
	virtual ~Entity() = 0;
};