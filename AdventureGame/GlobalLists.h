#pragma once
//Global lists for monsters, items and locations. This allows for variety and each round to feel different. Elements are randomly selected from each list for use  
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