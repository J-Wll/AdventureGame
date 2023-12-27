#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

#include "Monster.h"
#include "Location.h"
#include "Player.h"
#include "Tower.h"
#include "Item.h"
#include "AttackCycle.h"

// Declares large lists of possible Monsters, Location names and items
#include "GlobalLists.h"

int main() {
    using namespace std;
    
    //Pointer passed to sublist generation, removes selected monster from the global list to prevent duplicates
    vector<Monster>* monsterListPointer = &globalMonsterList;

    cout << "Welcome to the tower of ???\n" <<
        "In this game you will face 10 rounds of combat against groups of monsters as you climb the tower\n"<<
        "Each sucessfully completed round will grant you a reward and a full heal\n"<<
        "A boss resides at the top of the tower\n"<<
        "Fire types are effective against earth, earth against water and water against fire\n"<<
        "Neutral types are equally effective against all types\n"
        "Lets build the team you'll use to climb this tower:\n\n";

    // seeded in main to prevent error
    srand(time(NULL));

    Player* player = new Player("Bob");
    player->chooseMonsters(monsterListPointer);
    Item* testItem = new Item("testItem", "Common", 20, 40, 30);
    player->party.getParty()->at(0).setEquipment(testItem);

    // Main game loop
    for (int i = 0; i < 3; i++) {
        int randomNum = rand() % globalLocationNamesList.size();
        string randomLocationName = globalLocationNamesList[randomNum];
        globalLocationNamesList.erase(globalLocationNamesList.begin() + randomNum);
        Location* currentLocation = new Location(randomLocationName);

        currentLocation->enter();
        currentLocation->genMonsters(monsterListPointer);

        player->showPlayersParty();
        currentLocation->showMonsters();

        // cycle of every player monster fighting every location monster (for testing), (final version in a loop with a location var that changes)
        attackCycle(player, currentLocation);
        // if player party gets wiped, fail message of location
        //currentLocation->fail();
        currentLocation->finish();
    }

    cout << "Game over, thanks for playing";
}