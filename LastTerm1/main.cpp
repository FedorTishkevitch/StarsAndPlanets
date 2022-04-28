#include <iostream>
#include "planet.h"
#include "starSystem.h"
#include "fstream"

using namespace std;

int main() {
	cout << "Stars and Planets: \n";
	char chosingChar;
	cout << "n - new\n";
	cout << "l - load\n";
	cin >> chosingChar;
	if (chosingChar == 'l') {
		ifstream save;
		save.open("slot.txt");
		if (!save.eof()) {
			string starName;
			int planetsNumber;
			save >> starName;
			save >> planetsNumber;
			StarSystem curSystem(starName);
			for (int i = 0; i < planetsNumber; i++) {
				string name;
				int sattelitesNumber;
				double mass;
				save >> name;
				save >> sattelitesNumber;
				save >> mass;
				Planet planet(name, sattelitesNumber, mass);
				planet.getInfo();
				curSystem.add(Planet(name, sattelitesNumber, mass));
			}
			system("cls");
			cout << curSystem.getInfo();
		}
	}
}
