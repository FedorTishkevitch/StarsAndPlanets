#include <iostream>
#include <string>
#include "starSystem.h"

using namespace std;

StarSystem::StarSystem() {
	starName = "null";
	planetsNumber = 0;
	planets = NULL;
}
StarSystem::StarSystem(string starName, int planetsNumber, Planet* planets) {
	this->starName = starName;
	this->planetsNumber = planetsNumber;
	this->planets = planets;
}
StarSystem::StarSystem(string starName) {
	this->starName = starName;
}
StarSystem::StarSystem(const StarSystem& starSystem) {
	this->starName = starSystem.starName;
	this->planetsNumber = starSystem.planetsNumber;
	this->planets = new Planet[starSystem.planetsNumber];
	for (int i = 0; i < planetsNumber; i++) {
		*(this->planets + i) = *(starSystem.planets + i);
	}
}
StarSystem::~StarSystem() {
	delete[] planets;
}
void StarSystem::setStarSystem(StarSystem starSystem) {
	this->starName = starSystem.getName();
	this->planetsNumber = starSystem.getPlanetsNumber();
	int planetsNumber = starSystem.getPlanetsNumber();
	this->planets = new Planet[planetsNumber];
	for (int i = 0; i < planetsNumber; i++) {
		*(this->planets + i) = *starSystem.getPlanet(i);
	}
}
string StarSystem::getName() {
	return starName;
}
void StarSystem::setName(string starName) {
	this->starName = starName;
}
int StarSystem::getPlanetsNumber() {
	return planetsNumber;
}
string StarSystem::getInfo() {
	string result = "Star: " + starName + " planets: ";
	for (int i = 0; i < planetsNumber; i++) {
		result += to_string(i + 1) + "-" + (planets + i)->getName() + "; ";
	}
	return result;
}
Planet StarSystem::getPlanet(int index) const{
	if (index >= 0 && index < planetsNumber) {
		return *(planets + index);
	}
	return Planet();
}
Planet* StarSystem::getPlanet(int index) {
	if (index >= 0 && index < planetsNumber) {
		return (planets + index);
	}
	Planet planet;
	return &planet;
}
void StarSystem::add(Planet planet) {
	if (planetsNumber < MAX_PLANETS_NUMBER) {
		Planet* newPlanets = new Planet[planetsNumber + 1];
		for (int i = 0; i < planetsNumber; i++) {
			*(newPlanets + i) = *(planets + i);
		}
		*(newPlanets + planetsNumber) = planet;
		delete[] planets;
		planets = newPlanets;
		planetsNumber++;
	}
}
void StarSystem::remove(int index) {
	if (planetsNumber > MIN_PLANETS_NUMBER && index > 0 && index < planetsNumber && planets != NULL) {
		Planet* newPlanets = new Planet[planetsNumber - 1];
		int newPlanetsCurIndex = 0;
		for (int i = 0; i < planetsNumber; i++) {
			if (index != i) {
				*(newPlanets + newPlanetsCurIndex) = *(planets + i);
				newPlanetsCurIndex++;
			}
		}
		delete[] planets;
		planets = newPlanets;
		planetsNumber--;
	}
}
