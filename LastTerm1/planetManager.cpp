#include <iostream>
#include "starSystem.h"
#include "planet.h"
#include "planetManager.h"
#include "livePlanet.h"

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
			char typeChar;
			cin >> typeChar;
			if (typeChar == 'l') {
				string name;
				int sattelitesNumber;
				double mass;
				string liveName;
				int population;
				file >> name;
				file >> sattelitesNumber;
				file >> mass;
				file >> liveName;
				file >> population;
				curSystem.add(LivePlanet(name, sattelitesNumber, mass, liveName, population));
			}
			else {
				string name;
				int sattelitesNumber;
				double mass;
				file >> name;
				file >> sattelitesNumber;
				file >> mass;
				curSystem.add(Planet(name, sattelitesNumber, mass));
			}
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
		string gettedPlanetClass = typeid(starSystem.getPlanet(i)).name();
		if (gettedPlanetClass == "class Live Planet") {
			LivePlanet planet = starSystem.getPlanet(i);
			file << "l ";
			file << planet.getName() << " ";
			file << planet.getSattelitesNumber() << " ";
			file << planet.getMass() << " ";
			file << planet.getLiveName() << " ";
			file << planet.getPopulation() << " ";
		}
		else {
			Planet planet = starSystem.getPlanet(i);
			file << "p ";
			file << planet.getName() << " ";
			file << planet.getSattelitesNumber() << " ";
			file << planet.getMass() << " ";
		}
	}
}

void PlanetManager::removeStarSystem(int index, string path) {
	ifstream oldFile;
	oldFile.open(path);
	string oldSaves;
	int curIndex = 1;
	while (!oldFile.eof() && curIndex < index) {
		string str;
		getline(oldFile, str);
		oldSaves += str + "\n";
		getline(oldFile, str);
		if (oldFile.eof()) {
			oldSaves += str;
		}
		else {
			oldSaves += str + "\n";
		}
		curIndex++;
	}
	string saveToRemove;
	getline(oldFile, saveToRemove);
	getline(oldFile, saveToRemove);
	while (!oldFile.eof()) {
		string str;
		getline(oldFile, str);
		oldSaves += str + "\n";
		getline(oldFile, str);
		if (oldFile.eof()) {
			oldSaves += str;
		}
		else {
			oldSaves += str + "\n";
		}
		curIndex++;
	}
	ofstream newFile;
	newFile.open(path);
	newFile << oldSaves;
}

string PlanetManager::searchStarSystem(string searchingStarName, string path) {
	ifstream file;
	file.open(path);
	string result = "";
	int count = 1;
	while (!file.eof()) {
		string starName;
		getline(file, starName);
		if (starName.find(searchingStarName) != string::npos) {
			result += to_string(count) + " " + starName + "\n";
		}
		getline(file, starName);
		count++;
	}
	return result;
}