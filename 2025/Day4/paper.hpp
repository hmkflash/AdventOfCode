#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Returns the number of rolls of paper that can be removed after one pass.
int partOne(std::string inputName);

// Returns the number of rolls of paper that can be removed in total.
int partTwo(std::string inputName);

// Generates the vector off of a inputName.
void parseData(std::string inputName);

// Returns the number of rolls of paper that can be removed from one round of parsing.
int parseOneRound(std::string log);

// Takes in arguments to determine which parts to run.
int main(int argc, char* arv[]);
