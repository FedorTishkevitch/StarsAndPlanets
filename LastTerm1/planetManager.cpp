#include <iostream>
#include "starSystem.h"

double calculateAvgMass(StarSystem starSystem) {
	int planetsNumber = starSystem.getPlanetsNumber();
	double mass = 0;
	for (int i = 0; i < planetsNumber; i++) {
		 mass += starSystem.getPlanet(i).getMass();
	}
	return mass / planetsNumber;
}