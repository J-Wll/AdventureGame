#include <vector>

#include "GlobalLists.h"
#include "Monster.h"
#include "Item.h"


// Global lists for monsters, items and locations. This allows for variety and each round to feel different. Elements are randomly selected from each list for use  
// Global list of possible monsters
// Name, Type, HP, ATK, DEF
vector<Monster> globalMonsterList = {
    Monster("Wolf", "Neutral", 40, 70, 40),
    Monster("Shark", "Water", 50, 70, 40),
    Monster("Dragon", "Fire", 60, 75, 60),
    Monster("Golem", "Earth", 80, 40, 50),
    Monster("Goblin", "Neutral", 40, 60, 50),
    Monster("Mermaid", "Water", 60, 50, 60),
    Monster("Phoenix", "Fire", 50, 70, 50),
    Monster("Rock Elemental", "Earth", 70, 40, 60),
    Monster("Centaur", "Neutral", 50, 50, 50),
    Monster("Kraken", "Water", 60, 60, 60),
    Monster("Salamander", "Fire", 40, 60, 40),
    Monster("Ent", "Earth", 60, 40, 50),
    Monster("Lava Serpent", "Fire", 40, 70, 40),
    Monster("Sand Golem", "Earth", 60, 40, 60),
    Monster("Dryad", "Neutral", 50, 60, 50),
    Monster("Leviathan", "Water", 70, 60, 50),
    Monster("Fire Sprite", "Fire", 40, 70, 50),
    Monster("Mountain Troll", "Earth", 60, 50, 40),
    Monster("Spectral Wraith", "Neutral", 45, 65, 35),
    Monster("Chimera", "Fire", 65, 65, 50),
    Monster("Sea Serpent", "Water", 65, 55, 45),
    Monster("Stone Behemoth", "Earth", 70, 45, 65),
    Monster("Desert Scorpion", "Earth", 55, 30, 55),
    Monster("Wicked Imp", "Neutral", 45, 55, 45),
    Monster("Vampire Bat", "Neutral", 50, 60, 40),
    Monster("Radiant Angel", "Neutral", 70, 70, 65),
    Monster("Iron Gorgon", "Earth", 85, 55, 75),
    Monster("Lunar Guardian", "Neutral", 55, 65, 65),
    Monster("Frostwyrm", "Water", 70, 75, 60),
    Monster("Coral Guardian", "Water", 65, 50, 60),
    Monster("Silent Shade", "Neutral", 50, 65, 35),
    Monster("Sandstorm Specter", "Earth", 70, 50, 55),
    Monster("Ethereal Wanderer", "Neutral", 60, 65, 50),
    Monster("Volcanic Drake", "Fire", 55, 60, 55),
    Monster("Ancient Oak", "Earth", 70, 40, 60),
    Monster("Crystal Guardian", "Neutral", 70, 60, 55),
    Monster("Cerulean Spirit", "Water", 65, 70, 55),
    Monster("Tidal Enchantress", "Water", 60, 65, 55),
    Monster("Quake Titan", "Earth", 60, 80, 80),
};

// Global list of location names
vector<std::string> globalLocationNamesList = {
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

// Global list of items that can show in locations
vector<Item> globalItemList = {
     Item("Power Gem", "Common", 20, 20, 0),
     Item("Abyssal Dagger", "Uncommon", 0, 40, 10),
     Item("Elixir of Vitality", "Rare", 50, 0, 0),
     Item("Flame Sword", "Common", 10, 30, 5),
     Item("Phoenix Feather", "Legendary", 100, 50, 30),
     Item("Thunder Wand", "Rare", 30, 55, 15),
     Item("Silver Shield", "Uncommon", 45, 10, 25),
     Item("Mystic Robe", "Common", 25, 15, 10),
     Item("Soul Stone", "Epic", 70, 35, 20),
     Item("Frostblade", "Rare", 15, 55, 15),
     Item("Ruby Amulet", "Common", 30, 5, 5),
     Item("Emerald Dagger", "Uncommon", 5, 35, 5),
     Item("Sapphire Ring", "Rare", 45, 10, 20),
     Item("Diamond Sword", "Epic", 20, 85, 15),
     Item("Platinum Shield", "Legendary", 50, 30, 80),
     Item("Venomous Fang", "Common", 15, 35, 0),
     Item("Frost Staff", "Uncommon", 10, 50, 10),
     Item("Aegis Plate", "Rare", 60, 10, 35),
     Item("Celestial Robe", "Rare", 40, 20, 35),
     Item("Inferno Blade", "Epic", 25, 80, 25),
     Item("Stormcaller", "Legendary", 60, 80, 40),
     Item("Crystal Heart", "Epic", 80, 10, 50),
     Item("Doombringer", "Legendary", 10, 80, 10),
     Item("Opal Pendant", "Common", 25, 5, 5),
     Item("Assassin's Blade", "Uncommon", 5, 40, 5),
     Item("Crimson Ring", "Rare", 45, 35, 20),
     Item("Voidblade", "Rare", 10, 60, 15),
};

