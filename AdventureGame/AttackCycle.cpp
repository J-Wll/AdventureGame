#include <iostream>
#include "AttackCycle.h"
#include "Location.h"
#include "Player.h"

void test12345() {
	std:: cout << "ofijasoif";
}

// takes a location, iterates over the monsters at the location for combat
// after combat, takes the item from that location
void attackCycle(Player* player, Location* currentLocation) {

	for (int i = 0; i < 3; i++) {

		int enemyPartySize = currentLocation->monsterParty.size();
		int playerPartySize = player->monsterParty.size();

		cout << "Which of your monsters should attack?, (Enter a whole number): ";
		int attacker = player->getTarget(playerPartySize) - 1;
		cout << "Choose an enemy to target, (Enter a whole number): ";
		int target = player->getTarget(enemyPartySize) - 1;

		Monster* mon = &player->monsterParty[attacker];
		Monster* attacking = &currentLocation->monsterParty[target];

		cout << "\n" << mon->getName() << " Attacks " << attacking->getName() <<
			" dealing " << attacking->takeDamage(mon->getAttack()) << " damage\n";

		if (attacking->getHp() <= 0) {
			currentLocation->monsterParty.erase(currentLocation->monsterParty.begin() + target);
		}
		player->showPlayersParty();
		currentLocation->showMonsters();
	}

	//for(Monster mon : monsterParty){


//}
	currentLocation->monsterPartyInfo();
}