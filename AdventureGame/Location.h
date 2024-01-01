#pragma once

#include "Party.h"

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