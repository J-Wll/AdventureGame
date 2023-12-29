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

    cout << "---Overview---\n\n"<<
        "Welcome to the tower of ???\n" <<
        "In this game you will face 5 rounds of combat against groups of monsters as you climb the tower\n"<<
        "Each sucessfully completed round will grant you a reward and a full heal\n"<<
        "A boss resides at the top of the tower\n"<<
        "\n---Combat info---\n\n"
        "Fire types are effective against earth, earth against water and water against fire\n"<<
        "Neutral types are equally effective against all types\n"<<
        "During combat, the monster you select will attack an enemy, while delivering the attack they will take damage equal to half the attack of the opponent\n"<<
        "\n---Start---\n\n"<<
        "Lets build the team you'll use to climb this tower:\n\n";

    // seeded in main to prevent error
    srand(time(NULL));

    Player* player = new Player("Bob");
    player->chooseMonsters(monsterListPointer);
    Item* testItem = new Item("testItem", "Common", 20, 40, 30);
    player->party.getParty()->at(0).setEquipment(testItem);
    int LOCATIONCOUNT = 5;

    // Main game loop
    for (int i = 0; i < LOCATIONCOUNT; i++) {
        // selects a random name for a location and removes it from the global list
        int randomNumLocation = rand() % globalLocationNamesList.size();
        string randomLocationName = globalLocationNamesList[randomNumLocation];
        globalLocationNamesList.erase(globalLocationNamesList.begin() + randomNumLocation);
        Location* currentLocation = new Location(randomLocationName);

        int randomNumItem = rand() % globalItemList.size();
        Item randomItem = globalItemList[randomNumItem];
        globalItemList.erase(globalItemList.begin() + randomNumItem);

        currentLocation->enter();
        currentLocation->genMonsters(monsterListPointer);

        player->showPlayersParty();
        currentLocation->showMonsters();

        // storing the original party to remove in combat changes afterwards(damage taking)
        vector<Monster> preCombatParty = *player->party.getParty();

        // cycle of every player monster fighting every location monster (for testing), (final version in a loop with a location var that changes)
        attackCycle(player, currentLocation);

        // if player party gets wiped, fail message of location
        //currentLocation->fail();
      
        //Reset party
        player->party.setParty(preCombatParty);

        currentLocation->finish();
        
        // Items only gained if not in the last section
        if (i != LOCATIONCOUNT) {
            cout << "\nYou find " << randomItem.getName() << " in " << currentLocation->getName() << "\n";
            randomItem.info();
            cout << "Choose a monster to equip the item (Enter a whole number): ";
            int target = player->getTarget(player->party.getParty()->size()) - 1;
            Monster* mon = &player->party.getParty()->at(target);
            mon->setEquipment(&randomItem);

        }
    }

    cout << "Game over, thanks for playing";
}