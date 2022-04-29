#include <iostream>
#include <string>
#include "planet.h"

using namespace std;

Planet::Planet() {
	name = "null";
	sattelitesNumber = 0;
	mass = 0;
}
Planet::Planet(string name, int sattelitesNumber, double mass) {
	this->name = name;
	this->sattelitesNumber = sattelitesNumber;
	this->mass = mass;
}
Planet::~Planet() {

}
void Planet::setPlanet(string name, int sattelitesNumber, double mass) {
	this->name = name;
	this->sattelitesNumber = sattelitesNumber;
	this->mass = mass;
}
string Planet::getName() {
	return name;
}
void Planet::setName(string name) {
	this->name = name;
}
int Planet::getSattelitesNumber() {
	return sattelitesNumber;
}
void Planet::setSattelitesNumber(int sattelitesNumber) {
	if (sattelitesNumber >= 0) {
		this->sattelitesNumber = sattelitesNumber;
	}
}
double Planet::getMass() {
	return mass;
}
void Planet::setMass(double mass) {
	if (mass >= 0) {
		this->mass = mass;
	}
}
string Planet::getInfo() {
	return name + ", sattelites number: " + to_string(sattelitesNumber) + ", mass: " + to_string(mass);
}
