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

    cout << "Welcome to the tower of ???\n" << "In this game you will face 10 rounds of combat as you climb the tower\n"<<"Each sucessfully defeated round will grant you an item or equipment\n"<<"First lets build your team:\n\n";

    // seeded in main to prevent error
    srand(time(NULL));

    string randomLocationName = globalLocationNamesList[rand() % globalLocationNamesList.size()];

    Player* player = new Player("Bob");
    player->chooseMonsters(monsterListPointer);
    player->showPlayersParty();

    Location* church = new Location(randomLocationName);
    Location* currentLocation = church;

    currentLocation->genMonsters(monsterListPointer);
    currentLocation->showMonsters();

    // cycle of every player monster fighting every location monster (for testing), (final version in a loop with a location var that changes)
    attackCycle(player, currentLocation);
    currentLocation->showMonsters();
}