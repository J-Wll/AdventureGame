#include "Monster.h"

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

Monster::Monster(string iname, string itype, int iMaxHp, int iatk, int idef) {
	name = iname;
	type = itype;
	maxHp = iMaxHp;
	hp = maxHp;
	atk = iatk;
	def = idef;
}

void Monster::info(string opt = "") {
	string cooldownText = "";
	if (cooldown > 0) {
		cooldownText = "\n---ON COOLDOWN FOR "  + to_string(cooldown) + " TURNS---";
	}
	cout << "\n---\n" << opt 
		<< setw(5) << left << "Name: " << setw(23) << left << name << " |  Type: " << type 
		<< "\nStats: HP: " << setw(3) << left << hp << " ATK: " << setw(3)
		<< left << atk << " DEF: " << setw(3) << left << def << " |  Equipped: " << equipped
		<< cooldownText;
}

int Monster::takeDamage(int attackValue) {
	int damageTaken = (attackValue / (def * 0.05));
	if (damageTaken <= 0) {
		return 0;
	}
	hp -= damageTaken;
	if (hp <= 0) {
		hp = 0;
	}
	return damageTaken;
}

int Monster::getHp() {
	return hp;
}

int Monster::getAttack() {
	int randomDmg = rand() % atk / 5;
	return atk + randomDmg;
}

void Monster::setName(string in) { name = in; };
string Monster::getName() { return name; };

void Monster::setType(string in) { type = in; };
string Monster::getType() { return type; };

void Monster::setEquipment(Item* item) {
	maxHp += item->itemHp;
	hp += item->itemHp;
	atk += item->itemAtk;
	def += item->itemDef;
	if (itemCount == 0) {
		equipped = item->getName();
	} else {
		equipped += ", " + item->getName();
	}
	itemCount += 1;
}

bool Monster::attack(Monster* attacking, string extraText) {
	if (cooldown == 0) {
		int attackValue = atk;
		string enemyType = attacking->getType();
		string effectiveAttack = "The attack was super effective!\n";

		if (type == "Fire" && enemyType == "Earth") {
			attackValue *= 1.5;
		} else if (type == "Earth" && enemyType == "Water") {
			attackValue *= 1.5;
		} else if (type == "Water" && enemyType == "Fire") {
			attackValue *= 1.5;
		} else {
			effectiveAttack = "";
		}
		
		cout << "\n" << extraText << name << " Attacks " << attacking->getName() <<
			" dealing " << attacking->takeDamage(attackValue) << " damage\n" << effectiveAttack;
		cout << "\n" << extraText << name << " Takes " << takeDamage(attacking->getAttack() / 4) << " damage during the combat\n";
		//cooldown number is 1 higher than reality because it goes down right after the attack
		cooldown += 2;
		//attacked
		return true;
	}
	else {
		cout << "\n" << name << " Is on cooldown\n\n";
		//didn't attack
		return false;
	}
}

void Monster::decreaseCooldown() {
	if (cooldown > 0) {
		cooldown -= 1;
	}
}

void Monster::resetHealth() {
	hp = maxHp;
}

bool Monster::operator==(const Monster& compare) {
	return (name == compare.name);
}