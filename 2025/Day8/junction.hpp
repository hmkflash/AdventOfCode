#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define ull unsigned long long

// This structure represents the coordinates of a junction box.
struct Box {
	ull x;
	ull y;
	ull z;
};

void constructBoxes(std::string inputName);

std::vector<std::pair<Box, Box>> findNClosestPairs3d(std::vector<Box> Boxes, int numOfPairs);

ull partOne(std::string inputName);

ull partTwo(std::string inputName);

// Takes in arguments to determine which parts to run.
int main (int argc, char* argv[]);
