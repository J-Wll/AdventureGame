#include <iostream>
#include "AttackCycle.h"
#include "Location.h"
#include "Player.h"

// takes a location, iterates over the monsters at the location for combat
// after combat, takes the item from that location

void deathCheck(Monster* checking, vector<Monster>* partyPtr, int target) {
	if (checking->getHp() <= 0) {
		cout << "\n" << checking->getName() << " has died\n";
		partyPtr->erase(partyPtr->begin() + target);
	}
}

bool attackCycle(Player* player, Location* currentLocation) {
	while (true) {

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
		mon->attack(attacking);

		//Check for death, remove from party and print message on death
		deathCheck(attacking, locationPartyPtr, target);
		deathCheck(mon, playerPartyPtr, attacker);

		if (playerPartyPtr->size() == 0) {
			cout << "Defeated";
			return true;
		}

		if (locationPartyPtr->size() == 0) {
			cout << "Victorious";
			return false;
		}

		player->party.partyDecreaseCooldown();
		currentLocation->party.partyDecreaseCooldown();


		//Display updated parties
		player->showPlayersParty();
		currentLocation->showMonsters();
	}

	//for(Monster mon : monsterParty){


//}
	currentLocation->party.monsterPartyInfo();
}

