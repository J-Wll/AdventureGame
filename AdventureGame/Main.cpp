//#include <list>
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

using namespace std;

int main() {
    Monster testMon = Monster("Default", "Neutral");
	vector<Monster> monsterList = {
      Monster("Wolf", "Neutral"),
      Monster("Shark", "Water"),
      Monster("Dragon", "Fire"),
      Monster("Golem", "Earth", 80, 20, 50),
      Monster("Goblin", "Neutral"),
      Monster("Mermaid", "Water"),
      Monster("Phoenix", "Fire"),
      Monster("Rock Elemental", "Earth"),
      Monster("Centaur", "Neutral"),
      Monster("Kraken", "Water"),
      Monster("Salamander", "Fire"),
      Monster("Ent", "Earth"),
      Monster("Lava Serpent", "Fire"),
      Monster("Sand Golem", "Earth"),
      Monster("Dryad", "Neutral"),
      Monster("Leviathan", "Water"),
      Monster("Fire Sprite", "Fire"),
      Monster("Mountain Troll", "Earth"),
	};

    cout << "Welcome to the tower of ???\n" << "In this game you will face 10 rounds of combat as you climb the tower\n"<<"Each sucessfully defeated round will grant you an item or equipment\n"<<"First lets build your team:\n\n";

    // seeded in main to prevent error
    srand(time(NULL));
    Player* player = new Player("Bob");
    player->chooseMonsters(monsterList);
    player->showPlayersParty();

    Location* church = new Location("Church");
    Location* currentLocation = church;

    currentLocation->genMonsters(monsterList);
    currentLocation->showMonsters();

    // cycle of every player monster fighting every location monster (for testing), (final version in a loop with a location var that changes)
    player->attackCycle(currentLocation);
    currentLocation->showMonsters();
}


/*
Monster("Snowman", "Ice"),
Monster("Yeti", "Ice"),
Monster("Ice Elemental", "Ice"),

*/