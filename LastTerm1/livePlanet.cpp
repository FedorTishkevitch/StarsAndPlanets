#include "livePlanet.h"
#include "string"

LivePlanet::LivePlanet() {
	Planet();
	liveName = "null";
	population = 0;
}
LivePlanet::LivePlanet(string name, int age, double mark, string liveName, int population) {
	Planet(name, age, mark);
	liveName = "null";
	population = 0;
}
LivePlanet::~LivePlanet() {

}
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
string LivePlanet::getInfo() {
	return Planet::getInfo() + "; liveName: " + liveName + "; population: " + to_string(population) + ";";
}