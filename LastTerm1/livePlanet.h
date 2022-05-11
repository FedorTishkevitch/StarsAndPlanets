#pragma once
#include <iostream>
#include "planet.h"

class LivePlanet : public Planet{
private:
	string liveName;
	int population;
public:
	static const char type = 'l';
	LivePlanet();
	LivePlanet(string name, int age, double mark, string liveName, int population);
	~LivePlanet();
	string getLiveName();
	void setLiveName(string liveName);
	int getPopulation();
	void setPopulation(int population);
	string getInfo();
};