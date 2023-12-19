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

using namespace std;

int main() {
    //Global lists for monsters, items and locations. This allows for variety and each round to feel different 
    //TODO: Move to different file to avoid main clutter
    //Global list of possible monsters
	vector<Monster> globalMonsterList = {
        Monster("Wolf", "Neutral", 40, 70, 40),
        Monster("Shark", "Water", 50, 60, 40),
        Monster("Dragon", "Fire", 60, 70, 20),
        Monster("Golem", "Earth", 80, 20, 50),
        Monster("Goblin", "Neutral", 30, 70, 50),
        Monster("Mermaid", "Water", 50, 40, 60),
        Monster("Phoenix", "Fire", 50, 60, 40),
        Monster("Rock Elemental", "Earth", 70, 20, 60),
        Monster("Centaur", "Neutral", 50, 50, 50),
        Monster("Kraken", "Water", 60, 50, 40),
        Monster("Salamander", "Fire", 40, 70, 40),
        Monster("Ent", "Earth", 60, 40, 50),
        Monster("Lava Serpent", "Fire", 40, 70, 40),
        Monster("Sand Golem", "Earth", 60, 30, 60),
        Monster("Dryad", "Neutral", 40, 60, 50),
        Monster("Leviathan", "Water", 70, 40, 40),
        Monster("Fire Sprite", "Fire", 30, 70, 50),
        Monster("Mountain Troll", "Earth", 60, 50, 40),
	};

    //Global list of location names
    vector<string> globalLocationNamesList = {
        "Howling Labyrinth",
        "Floor of Eternal Shadows",
        "Abyssal Nexus",
        "Cursed Crypt",
        "Serpentine Sanctum",
        "Dreadful Halls",
        "Harrowing Catacombs",
        "Necrotic Antechamber",
        "Chaos Chamber",
        "Malevolent Sanctum",
        "Spectral Spires",
        "Forsaken Vestibule",
        "Doomshade Quarters",
        "Cryptic Corridor",
        "Darkfire Abyss",
        "Sinister Sanctum",
        "Nightshade Chambers",
        "Eclipse Passage",
        "Raven's Roost",
        "Mystic Garden Floor",
        "Elysian Echoes Floor",
        "Infernal Inner Sanctum",
        "Vortex of Vanity",
        "Sable Stronghold",
        "Cryptic Conclave",
        "Enshrined Vault"
    };

    //Global list of items that can show in locations
    vector<Item> globalItemList = {};

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