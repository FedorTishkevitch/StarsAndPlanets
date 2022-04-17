#include <iostream>
#include "planet.h"
#include "starSystem.h"

using namespace std;

int main() {
	string starName;
	cout << "enter your star name: ";
	cin >> starName;
	StarSystem starSystem = StarSystem(starName, 0, NULL);

	int planetsNum;
	cout << "enter count of planets in your system (Max: " << starSystem.MAX_PLANETS_NUMBER << "): ";
	cin >> planetsNum;

	for (int i = 0; i < planetsNum; i++) {
		cout << "planet " << i + 1 << ":";
		cout << "enter name: ";
		string planetName;
		cin >> planetName;
		cout << "enter planet sattelites number: ";
		int sattelitesNumber;
		cin >> sattelitesNumber;
		cout << "enter planet mass: ";
		int mass;
		cin >> mass;
		Planet planet(planetName, sattelitesNumber, mass);
		starSystem.add(planet);
	}

	int chose = 0;

	while (chose != 1) {
		system("cls");
		cout << starSystem.getInfo() << "\n";
		cout << "1-done" << "\n";
		cout << "2-remove something" << "\n";
		cin >> chose;
		if (chose == 2) {
			int index;
			cout << "enter index to remove: ";
			cin >> index;
			starSystem.remove(index);
		}
	}
	cout << "Bye!";
}
