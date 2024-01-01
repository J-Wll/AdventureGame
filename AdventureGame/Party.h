#pragma once

// Stores Monsters and has relevant methods for Location and Player classes
#include "Monster.h"

class Party {
private:
	std::vector<Monster> monsterParty = {};
public:
	// Calls the .info method on each monster in a passed in monster list, passes the current index to the info function which is display in the terminal
	void monsterPartyInfo();
	std::vector<Monster> monsterSubList(std::vector<Monster>* monsterListPointer);
	std::vector<Monster>* getParty();
	void setParty(std::vector<Monster> iParty);
	void partyDecreaseCooldown();
	// Checks if there are monsters able to attack in the party
	bool availableMonsters();
};


