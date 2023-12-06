#include <iostream>
// not currently using list
#include <list>
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
	vector<Monster> monsterList = {
      Monster("Wolf", "Neutral"),
      Monster("Shark", "Water"),
      Monster("Dragon", "Fire"),
      Monster("Golem", "Earth", 80, 50, 20),
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

    /*
	for (Monster i : monsterList) {
		i.info();
	}
    */

    cout << "Welcome to the tower of ???\n" << "In this game you will face 10 rounds of combat as you climb the tower\n"<<"Each sucessfully defeated round will grant you an item or equipment\n"<<"First lets build your team:\n\n";

    Player* player = new Player("Bob");
    player->chooseMonsters(monsterList);
    player->showPlayersParty();
    Location* church = new Location("Church");
    church->genMonsters(monsterList);
    church->showMonsters();
}


/*
Monster("Snowman", "Ice"),
Monster("Yeti", "Ice"),
Monster("Ice Elemental", "Ice"),

*/