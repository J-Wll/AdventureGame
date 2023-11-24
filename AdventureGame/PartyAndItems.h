#pragma once

// list of monsters at that location, like 3 per?, dynamic array with monsters being removed/added?
// also a list of items/equipment (objects) 
// monsters and or equip could be randomly generated/selected from a bigger list

class PartyAndItems {

};

// always 3 monsters 1 item, limited lifespan?
class Location : public PartyAndItems {

};

// 3 monsters, up to 9 items, lasts the whole game
class Player : public PartyAndItems {

};