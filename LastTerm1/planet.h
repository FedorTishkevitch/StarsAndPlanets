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
	string getName();
	void setName(string name);
	int getSattelitesNumber();
	void setSattelitesNumber(int sattelitesNumber);
	double getMass();
	void setMass(double mass);
	string getInfo();
};
