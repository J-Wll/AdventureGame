#pragma once

#include "PartyAndItemsUtility.h"
#include "Player.h"
#include "Location.h"

// 3 monsters, up to 9 items, lasts the whole game

void Player::showPlayersParty() {
	cout << "\nPlayers party:";
	monsterPartyInfo();
}
int Player::getTarget(int max) {
	int min = 1;
	int inp;
	cin >> inp;
	if (inp > max || inp < min) {
		cout << "Invalid input, enter again:\n";
		return getTarget(max);
	}
	return inp;
};


void Player::chooseMonsters(vector<Monster> monsterList) {
	vector<Monster> tempMonsters = {};
	cout << "You will be presented with 3 choices, each with 3 options for your party, choose with 1/2/3\n";
	tempMonsters = monsterSubList(monsterList);
	//monsterListInfo(tempMonsters);
	monsterParty = tempMonsters;
};

