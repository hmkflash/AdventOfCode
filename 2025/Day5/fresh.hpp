#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define ull unsigned long long

// Entry just contains a pair of ulls a min and max of the id range.
struct entry {
	ull min; // minimum value of this range.
	ull max; // maximum value of this range.

	// Checks to see if an id value is within the range of the this entry.
	bool isInRange(ull value) {
		return (value >= min && value <= max);
	}
};

// Takes data from the input file and adds the data to ranges and ids.
void parseData(std::string inputName);

// Scans through the sorted list of id ranges and condenses them so if two id ranges overlap they merge.
void condense(std::vector<entry> &curRanges);

// Uses insertion sort to sort the id ranges based on their minimum values.
void sort(std::vector<entry> &curRanges);

// Takes a single range of ids and figures out how to add it to the prexisting list of ids.
void parseRange(entry range, std::vector<entry> &curRanges);

// Iterates over each individual id and checks to see if it is within the range of one of the id ranges.
ull partOne();

// Iterates over each id range and condenses it with the other ids.
ull partTwo();

// Takes in arguments to determine which parts to run.
int main(int argc, char* argv[]);
