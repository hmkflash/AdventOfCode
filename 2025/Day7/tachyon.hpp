#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

#define ull unsigned long long

void condense(std::vector<std::pair<size_t, ull>> &lasers);

void sort(std::vector<std::pair<size_t, ull>> &lasers);

// Iterates through the input file and calculates the number of splits and number of timelines.
void solveProblem(std::string inputName);

int main(int argc, char* argv[]);
