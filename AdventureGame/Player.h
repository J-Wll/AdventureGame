#pragma once

#include "Party.h"

// 3 monsters, up to 9 items, lasts the whole game
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
