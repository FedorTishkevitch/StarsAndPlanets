#include "livePlanet.h"
#include "string"

string LivePlanet::getLiveName() {
	return liveName;
}
void LivePlanet::setLiveName(string liveName) {
	this->liveName = liveName;
}
int LivePlanet::getPopulation() {
	return population;
}
void LivePlanet::setPopulation(int population) {
	this->population = population;
}