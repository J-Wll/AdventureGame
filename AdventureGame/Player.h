#pragma once
#include "PartyAndItemsUtility.h"

// 3 monsters, up to 9 items, lasts the whole game
class Player : public PartyAndItemsUtility {
private:
	// using the constructor of PartyAndItemsUtility
	using PartyAndItemsUtility::PartyAndItemsUtility;
	//vector<Monster> monsterParty = {};

public:
	void chooseMonsters(vector<Monster> monsterlist);
	void attackCycle(Location* currentLocation);
	void showPlayersParty() {
		cout << "\nPlayers party:";
		monsterPartyInfo();
	}
	int getTarget(int max = 3) {
		int min = 1;
		int inp;
		cin >> inp;
		if (inp > max || inp < min) {
			cout << "Invalid input, enter again:\n";
			return getTarget(max);
		}
		return inp;
	};
};

void Player::chooseMonsters(vector<Monster> monsterList) {
	vector<Monster> tempMonsters = {};
	cout << "You will be presented with 3 choices, each with 3 options for your party, choose with 1/2/3\n";
	tempMonsters = monsterSubList(monsterList);
	//monsterListInfo(tempMonsters);
	monsterParty = tempMonsters;
};

// takes a location, iterates over the monsters at the location for combat
// after combat, takes the item from that location
void Player::attackCycle(Location* currentLocation) {

	for (int i = 0; i < 3; i++) {

		int enemyPartySize = currentLocation->monsterParty.size();
		int playerPartySize = monsterParty.size();

		cout << "Which of your monsters should attack?, (Enter a whole number): ";
		int attacker = getTarget(playerPartySize) - 1;
		cout << "Choose an enemy to target, (Enter a whole number): ";
		int target = getTarget(enemyPartySize) - 1;

		Monster* mon = &monsterParty[attacker];
		Monster* attacking = &currentLocation->monsterParty[target];

		cout << "\n" << mon->getName() << " Attacks " << attacking->getName() <<
			" dealing " << attacking->takeDamage(mon->getAttack()) << " damage\n";

		if (attacking->getHp() <= 0) {
			currentLocation->monsterParty.erase(currentLocation->monsterParty.begin() + target);
		}
		showPlayersParty();
		currentLocation->showMonsters();
	}

	//for(Monster mon : monsterParty){
		

//}
	currentLocation->monsterPartyInfo();
}