#pragma once

#include "Party.h"

// always 3 monsters 1 item, limited lifespan?
class Location {
private:
	string name;
public:
	Party party;
	Location(string iname);
	string getName();
	void genMonsters(vector<Monster>* monsterListPointer);
	void showMonsters();
	void enter(string extraText = "");
	void fail();
	void finish();
};