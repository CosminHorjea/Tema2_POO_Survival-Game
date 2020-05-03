#pragma once

#include <iostream>
#include <string>
#include <time.h>

std::string names[20]={"Gwen","Trent","Geoff","DJ","Heather","Justin","Duncan","Harold","Courtney","Owen","Courtney","Beth","Duncan","Justin","Lindsay","Leshawna","Izzy","Dany","Casey","Chris"};

int randInt(int lower, int upper)
{
	return lower + rand() % (upper - lower);
}

std::string randName(){
	return(names[randInt(0,20)]);
}
