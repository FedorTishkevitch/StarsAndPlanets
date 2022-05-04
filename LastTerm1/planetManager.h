#pragma once
#include <iostream>
#include "starSystem.h"
#include "fstream"

class PlanetManager {
public:
	double calculateAvgMass(StarSystem starSystem);
	string getStarList(string path);
	StarSystem readStarSystem(string path, int index);
	void saveStarSystem(StarSystem starSystem, string path);
};