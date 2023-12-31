#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <iostream>
#include <windows.h>   

#include "Monster.h"
#include "Location.h"
#include "Player.h"
#include "Tower.h"
#include "Item.h"
#include "AttackCycle.h"

// Declares large lists of possible Monsters, Location names and items
#include "GlobalLists.h"
// Colour codes, sleep timers
#include "UtilityVariables.h"

int main() {
    using namespace std;
    //system("Color 1F");
    cout << defaultColour;
    
    //Pointer passed to sublist generation, removes selected monster from the global list to prevent duplicates
    vector<Monster>* monsterListPointer = &globalMonsterList;

    cout << "\n---Overview---\n\n" <<
        greenColour << "Welcome to the Umbraxis tower\n" << defaultColour <<
        "In this game you will face 5 rounds of combat against groups of monsters as you climb the tower\n" <<
        "Each sucessfully completed round will grant you a reward and a full heal\n" <<
        "A group of evil dragons resides at the top of the tower\n";
    Sleep(STDSLEEPTIME);
    cout <<
        "\n---Combat info---\n\n"
        "Fire types are effective against earth, earth against water and water against fire\n"<<
        "Neutral types are equally effective against all types\n"<<
        "During combat, the monster you select will attack an enemy\n"<<
        "While delivering the attack they will receive damage equal to 1/4 of the attack of the opponent (Regardless of type)\n";
    Sleep(STDSLEEPTIME);
    cout <<
        "\n---Start---\n\n"<<
        "Lets build the team you'll use to climb this tower:\n\n";

    // seeded in main to prevent error
    srand(time(NULL));

    Player* player = new Player("Bob");
    player->chooseMonsters(monsterListPointer);
    Item* startItem = new Item("Adventurers Blessing", "Common", 25, 25, 25);
    player->party.getParty()->at(0).setEquipment(startItem);
    int LOCATIONCOUNT = 5;
    // 1 extra for the boss floor
    LOCATIONCOUNT += 1;
    Location* currentLocation;

    // Main game loop
    for (int i = 0; i < LOCATIONCOUNT; i++) {
        // If on the final floor
        if (i == LOCATIONCOUNT - 1) {
            currentLocation = new Location("Tower Apex");
            vector<Monster> ApexMonsters = {
                Monster("Ignarius the Emberlord Dragon", "Fire", 75, 150, 75),
                Monster("Vortexia the Seaborn Dragon", "Water", 75, 75, 150),
                Monster("Stonewyrm the Terraforge Dragon", "Earth", 150, 75, 75),
                Monster("Cyrax the Elder Dragon", "Neutral", 150, 150, 150)
            };
            Item bossItem("Ring of Eternity", "Legendary", 50, 50, 50);
            ApexMonsters.at(3).setEquipment(&bossItem);
            currentLocation->party.setParty(ApexMonsters);
        }
        //Every non final floor
        else {
            // selects a random name for a location and removes it from the global list
            int randomNumLocation = rand() % globalLocationNamesList.size();
            string randomLocationName = globalLocationNamesList[randomNumLocation];
            globalLocationNamesList.erase(globalLocationNamesList.begin() + randomNumLocation);
            currentLocation = new Location(randomLocationName);
            currentLocation->genMonsters(monsterListPointer);
        }


        int randomNumItem = rand() % globalItemList.size();
        Item randomItem = globalItemList[randomNumItem];
        globalItemList.erase(globalItemList.begin() + randomNumItem);

        currentLocation->enter("\nFloor: " + to_string(i+1));

        Sleep(LRGSLEEPTIME);
        player->showPlayersParty();
        Sleep(STDSLEEPTIME);
        currentLocation->showMonsters();

        // storing the original party to remove in combat changes afterwards(damage taking)
        vector<Monster> preCombatParty = *player->party.getParty();

        // cycle of every player monster fighting every location monster (for testing), (final version in a loop with a location var that changes)
        bool defeated = attackCycle(player, currentLocation);

        if (defeated) {
            // if player party gets wiped, fail message of location
            currentLocation->fail();
            break;
        }
        else {
            currentLocation->finish();
        }

        //Reset party
        player->party.setParty(preCombatParty);

        
        // Items only gained if not in the last section
        if (i != LOCATIONCOUNT - 1) {
            cout << "\nYou find " << randomItem.getName() << " in " << currentLocation->getName() << "\n";
            randomItem.info();
            player->showPlayersParty();
            cout << "Choose a monster to equip the item (Enter a whole number): ";
            int target = player->getTarget(player->party.getParty()->size()) - 1;
            Monster* mon = &player->party.getParty()->at(target);
            mon->setEquipment(&randomItem);

        }
    }

    cout << "Game over, thanks for playing";
    Sleep(LRGSLEEPTIME);
}