#include <iostream>
#include <string>
#include "planet.h"

using namespace std;

class StarSystem {
private:
	string starName;
	int planetsNumber;
	Planet* planets;
public:
	const int MIN_PLANETS_NUMBER = 0;
	const int MAX_PLANETS_NUMBER = 12;
	StarSystem();
	StarSystem(string starName, int planetsNumber, Planet* planets);
	StarSystem(string starName);
	~StarSystem();
	string getName();
	string setName(string starName);
	string getInfo();
	void add(Planet planet);
	void remove(int index);
};