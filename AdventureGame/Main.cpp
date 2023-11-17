#include <iostream>
#include <list>
#include "Monster.h"
using namespace std;

int main() {
	list<Monster> monsterList = {
      Monster("Wolf", "Neutral"),
      Monster("Shark", "Water"),
      Monster("Dragon", "Fire"),
      Monster("Yeti", "Ice"),
      Monster("Golem", "Earth"),
      Monster("Goblin", "Neutral"),
      Monster("Mermaid", "Water"),
      Monster("Phoenix", "Fire"),
      Monster("Ice Elemental", "Ice"),
      Monster("Rock Elemental", "Earth"),
      Monster("Centaur", "Neutral"),
      Monster("Kraken", "Water"),
      Monster("Salamander", "Fire"),
      Monster("Snowman", "Ice"),
      Monster("Treant", "Earth")
	};

	for (Monster i : monsterList) {
		i.info();
		// cout << "Monster name: " << i.getName()<< "\nMonster type: " << i.getType() << "\n";
	}
}