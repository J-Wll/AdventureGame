#pragma once
#include <iostream>
#include <list>
using namespace std;

// monster class used for player and enemies, has type, attack, def, speed
// moves based on type?
// player picks their party at the start?
// party size of 3?
class Monster
{
	string name;
	string type;
public:
	Monster(string iname, string itype);
	void info();
	void setName(string in);
	string getName();
	void setType(string in);
	string getType();
};

Monster::Monster(string iname, string itype) {
	name = iname;
	type = itype;
}

void Monster::setName(string in) {
	name = in;
}

string Monster::getName() {
	return name;
}

void Monster::setType(string in) {
	type = in;
}

string Monster::getType() {
	return type;
}

void Monster::info() {
	cout << "This monsters name is: " << name << "\nIts type is: " << type << "\n --- \n";
}