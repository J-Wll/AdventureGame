#include <iostream>
#include "AttackCycle.h"
#include "Location.h"
#include "Player.h"

// takes a location, iterates over the monsters at the location for combat
// after combat, takes the item from that location
void attackCycle(Player* player, Location* currentLocation) {

	for (int i = 0; i < 3; i++) {

		vector<Monster>* playerPartyPtr = player->party.getParty();
		vector<Monster>* locationPartyPtr = currentLocation->party.getParty();

		//Inputs for attack
		cout << "Which of your monsters should attack?, (Enter a whole number): ";
		int attacker = player->getTarget(playerPartyPtr->size()) - 1;
		cout << "Choose an enemy to target, (Enter a whole number): ";
		int target = player->getTarget(locationPartyPtr->size()) - 1;

		//Getting the monster and what it is targeting
		Monster* mon = &playerPartyPtr->at(attacker);
		Monster* attacking = &locationPartyPtr->at(target);

		//Attack and message
		cout << "\n" << mon->getName() << " Attacks " << attacking->getName() <<
			" dealing " << attacking->takeDamage(mon->getAttack()) << " damage\n";

		//Check for death
		if (attacking->getHp() <= 0) {
			cout << "\n" << attacking->getName() << " has died\n";
			locationPartyPtr->erase(locationPartyPtr->begin() + target);
		}

		//Display updated parties
		player->showPlayersParty();
		currentLocation->showMonsters();
	}

	//for(Monster mon : monsterParty){


//}
	currentLocation->party.monsterPartyInfo();
}