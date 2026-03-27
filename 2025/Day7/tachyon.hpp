#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

#define ull unsigned long long

// Checks adjacent pairs for the same index and condenses dublicates into one entry.
void condense(std::vector<std::pair<size_t, ull>> &lasers);

// Uses Insertion Sort to sort the pairs of lasers.
void sort(std::vector<std::pair<size_t, ull>> &lasers);

// Iterates through the input file and calculates the number of splits and number of timelines.
void solveProblem(std::string inputName);

// Takes in arguments to determine which totals to print.
int main(int argc, char* argv[]);
