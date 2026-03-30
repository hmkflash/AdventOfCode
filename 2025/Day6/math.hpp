#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#define ull unsigned long long

// Inserts the data from the input file into nums and ops. 
void parseDataPartOne(std::string inputName);

// Inserts the data from the input file into nums and ops. 
void parseDataPartTwo(std::string inputName);

// Iterates over the numbers within the problem and solves the problem according to the op.
ull solveProblem(std::vector<ull> numSet, char op);

// Iterates through each problem set and adds its calculation to the total.
ull partOne(std::string inputName);

// Takes in arguments to determine which parts to run.
ull partTwo(std::string inputName);

// Takes in arguments to determine which parts to run.
int main (int argc, char* argv[]);
