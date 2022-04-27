#pragma once
#include <iostream>
#include "planet.h"

class LivePlanet : Planet {
private:
	string liveName;
	int population;
public:
	string getLiveName() {
		return liveName;
	}
	void setLiveName(string liveName) {
		this->liveName = liveName;
	}
	int getPopulation() {
		return population;
	}
	void setPopulation(int population) {
		this->population = population;
	}
};