#pragma once

#include "Party.h"

class Player {
private:
	string name;
public:
	Party party;
	Player(string iname);
	string getName();
	void chooseMonsters(vector<Monster>* monsterListPointer);
	void showPlayersParty();
	int getTarget(int max = 3);
};
