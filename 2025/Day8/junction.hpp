#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define ull unsigned long long

// This structure represents the coordinates of a junction box.
struct Box {
	ull x;
	ull y;
	ull z;
};

// Thus structure represents the Boxes in a pair and the distance between them.
struct ClosePair{
	long double distance;
	Box a;
	Box b;
};

void constructBoxes(std::string inputName);

std::vector<ClosePair> findNClosestPairs3d(std::vector<Box>::iterator first, std::vector<Box>::iterator last, int numOfPairs);

ull partOne(std::string inputName);

ull partTwo(std::string inputName);

// Takes in arguments to determine which parts to run.
int main (int argc, char* argv[]);
