#include "boat.h"
using namespace std;

//contructor
//Boat::Boat() {}; contructor predefinido

Boat::Boat(string pName, int pVelocity, int pTraveledDistance, int pNitro, bool pNitroUsed) {
	name = pName;
	velocity = pVelocity;
	traveledDistance = pTraveledDistance;
	nitro = pNitro;
}

//getters
string Boat::getName() {
	return name;
}

int Boat::getVelocity() {
	return velocity;
}

int Boat::getTraveledDistance() {
	return traveledDistance;
}

int Boat::getNitro() {
	return nitro;
}

bool Boat::getNitroUsed() {
	return nitroUsed;
}
//setters
void Boat::setName(string pName) {
	name = pName;
}

int Boat::setVelocity(int pVelocity) {
	velocity = pVelocity;
	return velocity;
}

int Boat::setTraveledDistance(int pTraveledDistance) {
	traveledDistance = pTraveledDistance;
	return traveledDistance;
}

int Boat::setNitro(int pNitro) {
	nitro = pNitro;
	return nitro;
}

bool Boat::setNitroUsed(bool pNitroUsed) {
	nitroUsed = pNitroUsed;
	return nitroUsed;
}

//methods
int Boat::momentaryVelocity(int pRandomDiceForVelocity) {
    velocity += pRandomDiceForVelocity;
   	return velocity;
}

int Boat::momentaryTraveledDistance(int pVelocity) {
	traveledDistance += pVelocity * 100;
	return traveledDistance;
}

