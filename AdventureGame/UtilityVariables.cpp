#include <string>

// colour codes for terminal output https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
std::string redColour = "\033[1;91m";
std::string greenColour = "\033[1;92m";
std::string defaultColour = "\033[1;97m";

// Ms, used with the Sleep function to make output less overwhelming
//int STDSLEEPTIME = 1000;
//int SMLSLEEPTIME = 300;
//int LRGSLEEPTIME = 2000;

// Testing values (shorter time so script can play through quickly)
int STDSLEEPTIME = 1;
int SMLSLEEPTIME = 1;
int LRGSLEEPTIME = 1;