#pragma once
#include <iostream>
#include <time.h>
int randInt(int lower, int upper)
{
	return lower + rand() % (upper - lower);
}