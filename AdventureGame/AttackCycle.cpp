#include <iostream>
#include "AttackCycle.h"
#include "Location.h"
#include "Player.h"

// takes a location, iterates over the monsters at the location for combat
// after combat, takes the item from that location

int deathCheck(Monster* checking, vector<Monster>* partyPtr, int target, bool player = false) {
	if (checking->getHp() <= 0) {
		cout << "\n" << checking->getName() << " has died\n";
		partyPtr->erase(partyPtr->begin() + target);
	}
	if (partyPtr->size() == 0) {
		if (player) {
			cout << "Defeated";
			return 1;
		}
		else {
			cout << "Victorious";
			return 2;
		}
	}
	return 0;
}

bool attackCycle(Player* player, Location* currentLocation) {
	while (true) {
		Monster* mon;
		Monster* attacking;
		int attacker;
		int target;
		vector<Monster>* playerPartyPtr = player->party.getParty();
		vector<Monster>* locationPartyPtr = currentLocation->party.getParty();

		// Player attack
		while (true) {
			//Inputs for attack
			cout << "Which of your monsters should attack?, (Enter a whole number): ";
			attacker = player->getTarget(playerPartyPtr->size()) - 1;
			cout << "Choose an enemy to target, (Enter a whole number): ";
			target = player->getTarget(locationPartyPtr->size()) - 1;

			//Getting the monster and what it is targeting
			mon = &playerPartyPtr->at(attacker);
			attacking = &locationPartyPtr->at(target);

			//Attack and message
			bool attackHappened = mon->attack(attacking);
			if (attackHappened) {
				break;
			}
		}

		//Check for death, remove from party and print message on death
		int playerStatus = deathCheck(mon, playerPartyPtr, attacker, true);
		int locationStatus = deathCheck(attacking, locationPartyPtr, target);

		if (playerStatus == 1) {
			return true;
		}
		if (locationStatus == 2) {
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

