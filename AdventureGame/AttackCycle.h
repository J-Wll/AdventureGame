#pragma once

#include "Location.h"
#include "Player.h"

// For combat
bool attackCycle(std::shared_ptr<Player> player, Location* currentLocation);