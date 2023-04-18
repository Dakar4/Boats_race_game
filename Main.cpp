#include "Boat.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int main() {
	srand(time(NULL));
	
	int numBoats, turn = 0, oldMaxTraveledDistance = 0;;
	char nitroChoice;
	vector<Boat> allBoats; //para usar el array de manera dinámica, si uso "new" no funciona (sin usar punteros) al no tener un constructor predeterminado.
	//boat lista[10]; con un array si usasemos constructor predefined
	cout << "--- SAILING BOATS ---\nHow many boats are going to play?\n";
	cin >> numBoats;

	for (int i = 0; i < numBoats; i++) {
		string boatName;

		cout << "Insert name for the boat number " << i + 1 << "\n";
		cin >> boatName;
		Boat myBoats(boatName, 0, 0, 1, true);
		allBoats.push_back(myBoats); //De esta forma cada vez que se hace el loop registro en mi vector el objeto myBoats con el distintivo nombre
	}
	
	while(turn < 5) {
		for (int i = 0; i < allBoats.size(); i++) {
			int randomDiceForVelocity = (rand() % 6) + 1;
			cout << "\n\033[31m" << allBoats[i].getName() << "'s turn\033[0m\n";
			cout << allBoats[i].getName() << " got a " << randomDiceForVelocity << " on the thrown dice!\n";
			allBoats[i].momentaryVelocity(randomDiceForVelocity);
			cout << "The velocity of "<< allBoats[i].getName()<< "'s boat is now " << allBoats[i].getVelocity() << "\n";
			
			if (allBoats[i].getNitroUsed()) {
				cout << "Do you want to use nitro? (Y/N)\n";
				do {
					cin >> nitroChoice;
					nitroChoice = toupper(nitroChoice);
					cout << "\n";

					if (nitroChoice == 'Y') {
						int randomForNitro = (rand() % 2);
						if (randomForNitro == 0) {
							allBoats[i].setNitro(randomForNitro);
							cout << "The nitro has not worked as expected" << "\n";
							allBoats[i].setVelocity(allBoats[i].getVelocity() / 2);
							cout << "The velocity of " << allBoats[i].getName() << "'s boat is now reduced to " << allBoats[i].getVelocity() << "\n";
						}
						else {
							allBoats[i].setNitro(randomForNitro);
							cout << "The nitro perfectly worked" << "\n";
							allBoats[i].setVelocity(allBoats[i].getVelocity() * 2);
							cout << "The velocity of " << allBoats[i].getName() << "'s boat is now increased to " << allBoats[i].getVelocity() << "\n";
						}
						allBoats[i].setNitroUsed(false);
					}
					else if (nitroChoice == 'N') {
						cout << "The nitro will stay disabled" << "\n";
					}
					else {
						cout << "Invalid input. Please enter 'Y' or 'N'\n";
					}
				} while (nitroChoice != 'Y' && nitroChoice != 'N');
			}
			else {
				cout << "No nitro left for " << allBoats[i].getName() << "'s boat\n";
			}

			allBoats[i].momentaryTraveledDistance(allBoats[i].getVelocity());
			cout << "Traveled distance for " << allBoats[i].getName() << "'s boat is " << allBoats[i].getTraveledDistance() << "\n";

			system("pause");

			cout << "\n";
		}
		turn++;
	}
	vector<string> maxValueBoatNames; //This vector will only be useful when we get a draw in the result, because we will need to store more than one name
	if (turn == 5) {
		for (int i = 0; i < allBoats.size(); i++) {
			if (allBoats[i].getTraveledDistance() > oldMaxTraveledDistance) {
				oldMaxTraveledDistance = allBoats[i].getTraveledDistance();
				maxValueBoatNames.clear();
				maxValueBoatNames.push_back(allBoats[i].getName());
			}
			else if (allBoats[i].getTraveledDistance() == oldMaxTraveledDistance) {
				maxValueBoatNames.push_back(allBoats[i].getName());
			}
		}
		for (int i = 0; i < maxValueBoatNames.size(); i++) {
			cout << maxValueBoatNames[i];
			if (i < maxValueBoatNames.size() - 1) {
				cout << " and ";
			}
		}
		if (maxValueBoatNames.size() > 1) {
			cout << " are the winners of the game!";
		}
		else if (maxValueBoatNames.size() == 1) {
			cout << " is the winner of the game!";
		}
	}
}