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

string PlanetManager::getStarList(string path) {
	ifstream file;
	file.open(path);
	string result = "";
	int count = 1;
	while (!file.eof()) {
		string starName;
		getline(file, starName);
		result += to_string(count) + " " + starName + "\n";
		getline(file, starName);
		count++;
	}
	return result;
}

StarSystem PlanetManager::readStarSystem(string path, int index) {
	ifstream file;
	file.open(path);
	int count = 1;
	while (count < index && !file.eof()) {
		string str;
		getline(file, str);
		getline(file, str);
		count++;
	}
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
	ifstream oldFile;
	oldFile.open(path);
	string oldSaves;
	while (!oldFile.eof()) {
		string str;
		getline(oldFile, str);
		oldSaves += str + "\n";
	}
	ofstream file;
	file.open(path);
	file << oldSaves;
	int planetsNumber = starSystem.getPlanetsNumber();
	file << starSystem.getName() << " \n";
	file << planetsNumber << " ";
	for (int i = 0; i < planetsNumber; i++) {
		Planet planet = starSystem.getPlanet(i);
		file << planet.getName() << " ";
		file << planet.getSattelitesNumber() << " ";
		file << planet.getMass() << " ";
	}
}