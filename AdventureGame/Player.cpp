#pragma once

#include <ios>
#include <limits>

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
	cout << "\nYour party:";
	party.monsterPartyInfo();
}

int Player::getTarget(int max) {
	int min = 1;
	int inp;
	cin >> inp;
	if (inp > max || inp < min) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, enter again:\n";
		return getTarget(max);
	}
	return inp;
};


void Player::chooseMonsters(vector<Monster>* monsterListPointer) {
	vector<Monster> finalParty;
	Party tempMonsters;
	cout << "You will be presented with 3 choices, each with 3 options for your party, choose with 1/2/3\n";
	
	for (int i = 0; i < 3; i++) {
		tempMonsters.setParty(party.monsterSubList(monsterListPointer));
		tempMonsters.monsterPartyInfo();
		cout << "Select a monster (Input Whole Number): ";
		int selected = getTarget(tempMonsters.getParty()->size()) - 1;
		finalParty.push_back(tempMonsters.getParty()->at(selected));
	}

	party.setParty(finalParty);
};

