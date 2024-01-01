#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>  

//#include <algorithm>
//#include <vector>
//#include <algorithm>

// Combat cycle for a location
#include "AttackCycle.h"
// Core gameplay loop
#include "GameLoop.h"
// Colour codes, sleep timers
#include "UtilityVariables.h"


int main() {
    using namespace std;
    cout << defaultColour;

    cout << "\n---Overview---\n\n" <<
        greenColour << "Welcome to the Umbraxis tower\n" << defaultColour <<
        "In this game you will face 5 rounds of combat against groups of monsters as you climb the tower\n" <<
        "Each sucessfully completed round will grant you a reward and a full heal\n" <<
        "A group of evil dragons resides at the top of the tower\n";
    Sleep(STDSLEEPTIME);
    cout <<
        "\n---Combat info---\n\n"
        "Fire types are effective against earth, earth against water and water against fire\n"<<
        "Neutral types are equally effective against all types\n"<<
        "During combat, the monster you select will attack an enemy\n"<<
        "While delivering the attack they will receive damage equal to 1/4 of the attack of the opponent (Regardless of type)\n";
    Sleep(STDSLEEPTIME);
    cout <<
        "\n---Start---\n\n"<<
        "Lets build the team you'll use to climb this tower:\n\n";

    // Seeded in main to prevent error
    srand(time(NULL));

    // Core gameplay loop
    gameLoop();

    cout << "Game over, thanks for playing";
    Sleep(LRGSLEEPTIME);
    Sleep(3000);
}