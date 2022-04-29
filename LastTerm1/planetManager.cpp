#include <iostream>
#include "starSystem.h"
#include "planet.h"
#include "planetManager.h"

double PlanetManager::calculateAvgMass(StarSystem starSystem) {
	int planetsNumber = starSystem.getPlanetsNumber();
	double mass = 0;
	for (int i = 0; i < planetsNumber; i++) {
		 mass += starSystem.getPlanet(i).getMass();
	}
	return mass / planetsNumber;
}

StarSystem PlanetManager::readStarSystem(string path) {
	ifstream file;
	file.open(path);
	if (!file.eof()) {
		string starName;
		int planetsNumber;
		file >> starName;
		file >> planetsNumber;
		StarSystem curSystem(starName);
		for (int i = 0; i < planetsNumber; i++) {
			string name;
			int sattelitesNumber;
			double mass;
			file >> name;
			file >> sattelitesNumber;
			file >> mass;
			curSystem.add(Planet(name, sattelitesNumber, mass));
		}
		return curSystem;
	}
	return StarSystem();
}

void PlanetManager::saveStarSystem(StarSystem starSystem, string path) {
	ofstream file;
	file.open(path);
	int planetsNumber = starSystem.getPlanetsNumber();
	file << starSystem.getName() << "\n";
	file << planetsNumber << "\n";
	for (int i = 0; i < planetsNumber; i++) {
		Planet planet = starSystem.getPlanet(i);
		file << planet.getName() << "\n";
		file << planet.getSattelitesNumber() << "\n";
		file << planet.getMass() << "\n";
	}
}