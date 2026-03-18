#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define ull unsigned long long

struct entry {
	ull min;
	ull max;

	bool isInRange(ull value) {
		return (value >= min && value <= max);
	}
};

void parseData(std::string inputName);

void condense(std::vector<entry> &curRanges);

void sort(std::vector<entry> &curRanges);

void parseRange(entry range, std::vector<entry> &curRanges);

ull partOne();

ull partTwo();

int main(int argc, char* argv[]);
