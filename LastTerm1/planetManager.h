#pragma once
#include <iostream>
#include "starSystem.h"
#include "fstream"

class PlanetManager {
public:
	double calculateAvgMass(StarSystem starSystem);
	StarSystem readStarSystem(string path);
	void saveStarSystem(StarSystem starSystem, string path);
};