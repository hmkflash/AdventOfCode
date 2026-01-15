#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

// Shorthand for unsigned long long, as some of the values used where too long for ints.
#define ull unsigned long long 

// Calculates the total sum of all invalid IDs as defined by part one.
ull partOne();

// Calculates the total sum of all invalid IDs as defined by part two.
ull partTwo();

// validates the IDs so that there are no dublicates within a single range.
void validateIDs();

// Takes in argumenbts to determine which parts to run.
int main(int argc, char* argv[]);
