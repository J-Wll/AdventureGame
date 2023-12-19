#pragma once
//Stores Monsters and has relevant methods for Location and Player classes
#include "Monster.h";

class Party {
private:
	vector<Monster> monsterParty = {};
public:
	// calls the .info method on each monster in a passed in monster list, passes the current index to the info function which is display in the terminal
	void monsterPartyInfo();
	vector<Monster> monsterSubList(vector<Monster>* monsterListPointer);
	vector<Monster>* getParty();
	void setParty(vector<Monster> inpParty);
};


