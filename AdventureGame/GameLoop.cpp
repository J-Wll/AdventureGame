#include <windows.h>   
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Item.h"
#include "Location.h"
#include "AttackCycle.h"
// Declares large lists of possible Monsters, Location names and items
#include "GlobalLists.h"
// Colour codes, sleep timers
#include "UtilityVariables.h"

using namespace std;

Item getRandomItem() {
    int randomNumItem = rand() % globalItemList.size();
    Item randomItem = globalItemList[randomNumItem];
    globalItemList.erase(globalItemList.begin() + randomNumItem);

    return randomItem;
}

Location* getRandomLocation(vector<Monster>* monsterListPointer, int currentRound) {
    Location* currentLocation;
    // Selects a random name for a location and removes it from the global list
    int randomNumLocation = rand() % globalLocationNamesList.size();
    string randomLocationName = globalLocationNamesList[randomNumLocation];
    globalLocationNamesList.erase(globalLocationNamesList.begin() + randomNumLocation);
    currentLocation = new Location(randomLocationName);
    currentLocation->genMonsters(monsterListPointer);

    // After first round, enemy party has a random item
    if (currentRound > 0) {
        Item enemyItem = getRandomItem();
        // Equip item to random monster in party
        currentLocation->party.getParty()->at(rand() % currentLocation->party.getParty()->size()).setEquipment(enemyItem);
    }
    return currentLocation;
}

void gameLoop() {
    using namespace std;
    // Pointer passed to sublist generation, removes selected monster from the global list to prevent duplicates
    vector<Monster>* monsterListPointer = &globalMonsterList;

    shared_ptr<Player> player(new Player());
    player->chooseMonsters(monsterListPointer);
    player->party.getParty()->at(0).setEquipment(Item("Adventurers Blessing", "Common", 25, 25, 25));
    int LOCATIONCOUNT = 5;
    // 1 extra for the boss floor
    LOCATIONCOUNT += 1;
    Location* currentLocation;

    // Main game loop
    for (int currentRound = 0; currentRound < LOCATIONCOUNT; currentRound++) {

        // If on the final floor, set the party to something specific
        if (currentRound == LOCATIONCOUNT - 1) {
            currentLocation = new Location("Tower Apex");
            vector<Monster> ApexMonsters = {
                Monster("Ignarius the Emberlord Dragon", "Fire", 80, 125, 80),
                Monster("Vortexia the Seaborn Dragon", "Water", 80, 80, 125),
                Monster("Stonewyrm the Terraforge Dragon", "Earth", 125, 80, 80),
                Monster("Cyrax the Elder Dragon", "Neutral", 150, 150, 150)
            };
            
            ApexMonsters.at(3).setEquipment(Item ("Ring of Eternity", "Legendary", 50, 50, 50));
            currentLocation->party.setParty(ApexMonsters);
        }
        // Every non final floor gets randomised monsters
        else {
            currentLocation = getRandomLocation(monsterListPointer, currentRound);
        }

        currentLocation->enter("\nFloor: " + to_string(currentRound + 1));

        Sleep(LRGSLEEPTIME);
        player->showPlayersParty();
        currentLocation->showMonsters();

        // Storing the original party to remove in combat changes afterwards(damage taking)
        vector<Monster> preCombatParty = *player->party.getParty();

        // Cycle of every player monster fighting every location monster (for testing), (final version in a loop with a location var that changes)
        bool defeated = attackCycle(player, currentLocation);

        if (defeated) {
            // If player party gets wiped, fail message of location
            currentLocation->fail();
            break;
        }
        else {
            currentLocation->finish();
        }

        // Reset party
        player->party.setParty(preCombatParty);


        // Items only gained if not in the last section
        if (currentRound != LOCATIONCOUNT - 1) {
            Item itemDrop = getRandomItem();
            cout << greenColour << "\nYou find " << itemDrop.getName() << " in " << currentLocation->getName() << defaultColour << "\n";
            itemDrop.info();
            player->showPlayersParty();
            cout << "Choose a monster to equip the item: ";
            int target = player->getTarget(player->party.getParty()->size()) - 1;
            Monster* mon = &player->party.getParty()->at(target);
            mon->setEquipment(itemDrop);

        }
        // After defeating the final boss
        else{
            cout << "\n\n---You have vanquished the evil of tower and earned your place in time immemorial---\n\n";
        }

        delete currentLocation;
    }
}