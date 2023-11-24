#include <iostream>
#include <list>

#include "Monster.h"
// player and location in PartyAndItems.h
#include "PartyAndItems.h"
#include "Tower.h"
#include "Item.h"

using namespace std;

int main() {
    Player* player = new Player("Bob");
    cout << "A " << player->getName() << "\n";
	list<Monster> monsterList = {
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

	for (Monster i : monsterList) {
		i.info();
		// cout << "Monster name: " << i.getName()<< "\nMonster type: " << i.getType() << "\n";
	}
}


/*
Monster("Snowman", "Ice"),
Monster("Yeti", "Ice"),
Monster("Ice Elemental", "Ice"),

*/