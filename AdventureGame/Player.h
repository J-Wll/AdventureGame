#pragma once
#include "PartyAndItemsUtility.h"

// 3 monsters, up to 9 items, lasts the whole game
class Player : public PartyAndItemsUtility {
private:
	// using the constructor of PartyAndItemsUtility
	using PartyAndItemsUtility::PartyAndItemsUtility;
	vector<Monster> playerMonsters = {};

public:
	void chooseMonsters(vector<Monster> monsterlist);
	void showPlayersParty() {
		cout << "\nPlayers party:";
		monsterListInfo(playerMonsters);
	}
};

void Player::chooseMonsters(vector<Monster> monsterList) {
	vector<Monster> tempMonsters = {};
	cout << "You will be presented with 3 choices, each with 3 options for your party, choose with 1/2/3\n";
	tempMonsters = monsterSubList(monsterList);
	// monsterListInfo(tempMonsters);
	playerMonsters = tempMonsters;

};