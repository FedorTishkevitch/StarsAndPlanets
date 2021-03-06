#pragma once
#include <iostream>
#include <string>

using namespace std;

class Planet {
private:
	string name;
	int sattelitesNumber;
	double mass;
public:
	Planet();
	Planet(string name, int sattelitesNumber, double mass);
	~Planet();
	void setPlanet(string name, int sattelitesNumber, double mass);
	string getName();
	void setName(string name);
	int getSattelitesNumber();
	void setSattelitesNumber(int sattelitesNumber);
	double getMass();
	void setMass(double mass);
	virtual string getInfo();
};
