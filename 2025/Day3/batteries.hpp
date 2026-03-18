#include <string>
#include <fstream>
#include <iostream>

#define ll long long

// Returns the sum of the highest voltages among battery banks as defined by part one.
ll partOne(std::string inputName);

// Returns the sum of the highest voltages among battery banks as defined by part two.
ll partTwo(std::string inputName);

// Returns the highest voltage of a single battery bank as defined by part two.
ll ptGreedy(std::string line);

// Takes in arguments to determine which parts to run.
int main(int argc, char* argv[]);
