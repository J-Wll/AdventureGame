#pragma once

#include "Party.h"
#include "Player.h"

// 3 monsters, up to 9 items, lasts the whole game

Player::Player(string iname) {
	name = iname;
}

string Player::getName() {
	return name;
}

void Player::showPlayersParty() {
	cout << "\nPlayers party:";
	party.monsterPartyInfo();
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


void Player::chooseMonsters(vector<Monster>* monsterListPointer) {
	vector<Monster> tempMonsters = {};
	cout << "You will be presented with 3 choices, each with 3 options for your party, choose with 1/2/3\n";
	tempMonsters = party.monsterSubList(monsterListPointer);
	//monsterListInfo(tempMonsters);
	party.setParty(tempMonsters);
};

