#pragma once

#include "Party.h"

// Locations the player fights through
class Location {
private:
	std::string name;
public:
	Party party;
	Location(std::string iname);
	std::string getName();
	void genMonsters(std::vector<Monster>* monsterListPointer);
	void showMonsters();
	void enter(std::string extraText = "");
	void fail();
	void finish();
};