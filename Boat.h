#pragma once
#include <iostream>
using namespace std;

class Boat {

private:
	//global vars
	string name;
	int velocity;
	int traveledDistance;
	int nitro;
	bool nitroUsed;

public:
	//getters
	string getName();
	int getVelocity();
	int getTraveledDistance();
	int getNitro();
	bool getNitroUsed();

	//setters
	void setName(string pName);
	int setVelocity(int pVelocity);
	int setTraveledDistance(int pTraveledDistance);
	int setNitro(int pNitro);
	bool setNitroUsed(bool pNitroUsed);

	//methods
	int momentaryVelocity(int pRandomDiceForVelocity);
	int momentaryTraveledDistance(int pVelocity);

	//constructor
	//boat(); contructor predefinido
	Boat(string pName, int pVelocity, int pTraveledDistance, int pNitro, bool pNitroUsed);
};
