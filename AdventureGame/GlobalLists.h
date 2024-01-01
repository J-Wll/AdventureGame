#pragma once

#include <vector>

#include "Monster.h"
#include "Item.h"

// Global lists for monsters, items and locations. This allows for variety and each round to feel different. Elements are randomly selected from each list for use  
// Global list of possible monsters
// Name, Type, HP, ATK, DEF
extern std::vector<Monster> globalMonsterList;

// Global list of location names
extern std::vector<std::string> globalLocationNamesList;

// Global list of items that can show in locations
extern std::vector<Item> globalItemList;

