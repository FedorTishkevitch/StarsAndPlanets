#include <iostream>
#include "planet.h"
#include "starSystem.h"
#include "planetManager.h"
#include "livePlanet.h"
#include "fstream"

using namespace std;

int main() {
	StarSystem curSystem;
	PlanetManager planetManager;
	char exitChar = 'c';
	while (exitChar != 'e') {
		mainMenu:
		system("cls");
		cout << typeid(curSystem).name() << "\n";
		cout << "Stars and Planets: \n";
		char chosingChar;
		cout << "n - new\n";
		cout << "l - load\n";
		cout << "e - edit saves\n";
		cin >> chosingChar;
		if (chosingChar == 'l') {
			int index;
			cout << "chose:\n";
			cout << planetManager.getStarList("slot.txt");
			cin >> index;
			StarSystem loadedSystem(planetManager.readStarSystem("slot.txt", index));
			system("cls");
			cout << loadedSystem.getInfo();
			curSystem.setStarSystem(loadedSystem);
			//planetManager.saveStarSystem(loadedSystem, "slot.txt");
			cout << "\npress any key to continue...";
			system("pause>nul");
		}
		else if (chosingChar == 'e') {
			char redactorChar = 'c';
			while (redactorChar != 'e') {
				system("cls");
				cout << planetManager.getStarList("slot.txt") << "\n";
				editSavesMenu:
				cout << "r-remove(index):\n";
				cout << "s-search:\n";
				cout << "e-exit:\n";
				cin >> redactorChar;
				if (redactorChar == 'r') {
					int index;
					cout << "enter index: ";
					cin >> index;
					planetManager.removeStarSystem(index, "slot.txt");
				}
				else if (redactorChar == 's') {
					string starName;
					cout << "enter star name: ";
					cin >> starName;
					string result = planetManager.searchStarSystem(starName, "slot.txt");
					system("cls");
					if (result.empty()) {
						cout << "no results\n";
					}
					else {
						cout << result;
					}
					goto editSavesMenu;
				}
				else {
					goto mainMenu;
				}
			}
		}
		else {
			string starName;
			int planetsNumber;
			cout << "enter star name:  ";
			cin >> starName;
			cout << "enter planets number:  ";
			cin >> planetsNumber;
			StarSystem newSystem(starName);
			if (planetsNumber > newSystem.MAX_PLANETS_NUMBER) {
				planetsNumber = newSystem.MAX_PLANETS_NUMBER;
			}
			else if (planetsNumber < newSystem.MIN_PLANETS_NUMBER) {
				planetsNumber = newSystem.MIN_PLANETS_NUMBER;
			}
			for (int i = 0; i < planetsNumber; i++) {
				char planetTypeChar;
				string planetName;
				int sattelitesNumber;
				double mass;
				cout << "enter planet type: \n";
				cout << "p-planet\n";
				cout << "l-live planet\n";
				cin >> planetTypeChar;
				cout << "enter planet type: \n";
				cout << "enter " << i + 1 << " planet name: ";
				cin >> planetName;
				cout << "enter sattelites number: ";
				cin >> sattelitesNumber;
				cout << "enter mass (1 = 1 earth mass): ";
				cin >> mass;
				if (planetTypeChar == 'l') {
					string liveName;
					int population;
					cout << "enter live name: ";
					cin >> liveName;
					cout << "enter population: ";
					cin >> population;
					LivePlanet livePlanet(planetName, sattelitesNumber, mass, liveName, population);
					newSystem.add(livePlanet);
				}
				else {
					Planet planet(planetName, sattelitesNumber, mass);
					newSystem.add(planet);
				}
			}
			cout << newSystem.getInfo();
			curSystem.setStarSystem(newSystem);
			cout << "\npress any key to continue...";
			system("pause>nul");
		}
		char redactorChar = 'c';
		while (redactorChar != 'e') {
			system("cls");
			cout << curSystem.getInfo();
			cout << "\na-add\n";
			cout << "r-remove\n";
			cout << "s-save\n";
			cout << "n-restart\n";
			cout << "e-exit\n";
			cin >> redactorChar;
			if (redactorChar == 'a') {
				system("cls");
				string planetName;
				int sattelitesNumber;
				double mass;
				cout << "enter planet name: ";
				cin >> planetName;
				cout << "enter sattelites number: ";
				cin >> sattelitesNumber;
				cout << "enter mass (1 = 1 earth mass): ";
				cin >> mass;
				Planet planet(planetName, sattelitesNumber, mass);
				curSystem.add(planet);
			}
			else if (redactorChar == 'r') {
				system("cls");
				int index;
				cout << "enter index: ";
				cin >> index;
				curSystem.remove(index);
			}
			else if (redactorChar == 's') {
				planetManager.saveStarSystem(curSystem, "slot.txt");
				cout << "saved!";
				cout << "\npress any key to continue...";
				system("pause>nul");
			}
			else if (redactorChar == 'n') {
				break;
			}
			else {
				exitChar = 'e';
				break;
			}
		}
	}
}
