#pragma once

#include "Party.h"

class Player {
private:
	std::string name;
public:
	Party party;
	Player(std::string iname);
	std::string getName();
	void chooseMonsters(std::vector<Monster>* monsterListPointer);
	void showPlayersParty();
	int getTarget(int max = 3);
};
