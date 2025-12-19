#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

// Resets global variables to their inital settings
void reset();

// rotates the dial a distance and returns the ending position.
int rotateDialOne(int distance);

// rotates the dial a distance and returns the number of times it hits 0.
int rotateDialTwo(int distance);

// Calculates the number of times an instruction ends on a zero.
void partOne();

// Calculates the number of times zero is encountered
void partTwo();

// Takes in arguments to determine which parts to run
int main(int argc, char* argv[]);
