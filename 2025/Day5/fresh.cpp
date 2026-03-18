/**
 * @author Holden Kuempel
 * 
 * This program was developed to solve the 2025 Advent of Code Day 5, parts 1 and 2.
 * 
 * The challenge involves a series of ids ranges and individual ids. In part one, it wanted the number of ids 
 * from the series of individual ids that are included in the series of ranges (those that are fresh). In part 
 * two, it wanted the total number of fresh ids as described from the series of fresh id ranges.
 * 
 * This program requires the name of an input file as the first argument and may take in an argument of 1 or 2. If 
 * it is provided it will only run that part of the challenge. Otherwise, it will run both parts.
 * 
 * To complete this challenge yourself go to: https://adventofcode.com/2025/day/5
 */

#include "fresh.hpp"

std::vector<entry> ranges;
std::vector<ull> ids;

void parseData(std::string inputName) {
	std::string line;
	std::ifstream input (inputName);
	if (input.is_open()) {
		while (getline(input, line)) {
			if (line.empty()) continue;
			size_t index = line.find('-');
			if (index == std::string::npos) {
				ids.push_back(std::stoull(line));
				continue;
			}
			entry temp;
			temp.min = std::stoull(line.substr(0, index));
			temp.max = std::stoull(line.substr(index + 1));
			ranges.push_back(temp);
		}
	}
	input.close();
}

void condense(std::vector<entry> &curRanges)
{
	for (size_t i = 0; i < curRanges.size() - 1; i++)
	{
		if (curRanges[i].max >= curRanges[i + 1].min) {
			curRanges[i].max = curRanges[i + 1].max;
			curRanges.erase(curRanges.begin() + 1 + i);
			i--;
		}
	}
}

void sort(std::vector<entry> &curRanges)
{
	for (size_t i = 1; i < curRanges.size(); i++) {
		entry cur = curRanges[i];
		int j = i - 1;
		while (j >= 0 && curRanges[j].min > cur.min) {
			curRanges[j + 1] = curRanges[j];
			j--;
		}
		curRanges[j + 1] = cur;
	}
}

void parseRange(entry range, std::vector<entry> &curRanges) {
	// Case 1: data structure is empty
	if (curRanges.empty()) {curRanges.push_back(range); return;}
	for (auto it = curRanges.begin(); it != curRanges.end(); it++) {
		// Case 2: New range is completely inside an existing range
		if (range.max <= it->max && range.min >= it->min)
		{
			return;
		}
		// Case 3.1: Full extention to a previous range
		if (range.min <= it->min && range.max >= it->max)
		{
			it->min = range.min;
			it->max = range.max;
			return;
		}
		// Case 3.2: Min extention
		else if (range.min <= it->min && range.max <= it->max && range.max >= it->min)
		{
			it->min = range.min;
			return;
		}
		// Case 3.3: Max extention
		else if (range.max >= it->min && range.min >= it->min && range.min <= it->max)
		{
			it->max = range.max;
			return;
		}
	}	
	// Case 4: New range is completely out side of all existing ranges
	curRanges.push_back(range);
}

ull partOne() {
	ull count = 0;
	std::ofstream output ("logPart1.txt");
	if (output.is_open()) {
		for (ull id : ids) {
			bool isFresh = false;
			output << id << '\t';
			for (entry range : ranges) {
				if (range.isInRange(id)) {
					isFresh = true;
					count++;
					output << range.min << " - " << range.max << std::endl;				
					break;
				}
			}
			if (!isFresh) {
				output << "Not fresh!" << std::endl;
			}
		}
	}
	output.close();
	return count;
}

ull partTwo() {
	std::vector<entry> parsedRanges;
	for (entry range : ranges) {
		parseRange(range, parsedRanges);
		sort(parsedRanges);
		condense(parsedRanges);
	}
	ull count = 0;
	std::ofstream output ("logPart2.txt");
	if (output.is_open()) {
		for (entry range : parsedRanges) {
			output << range.min << " - " << range.max << std::endl;
			count += 1 + (range.max - range.min);
		}
		output.close();
	}
	return count;
}

int main(int argc, char* argv[]) {
	if (argc >= 3 && *argv[2] == '1') {
		parseData(argv[1]);
		std::cout << "Running just Part One" << std::endl;
		std::cout << "Fresh IDs: " << partOne() << std::endl;
		return 0;
	} else if (argc >= 3 && *argv[2] == '2') {
		parseData(argv[1]);
		std::cout << "Running just Part Two" << std::endl;
		std::cout << "Fresh IDs: " << partTwo() << std::endl;
		return 0;
	} else if (argc >= 2) {
		parseData(argv[1]);
		std::cout << "Fresh IDs for Part One: " << partOne() << std::endl;
		std::cout << "Fresh IDs for Part Two: " << partTwo() << std::endl;
		return 0;
	} else {
		std::cerr << "No input file provided, first argument should be the name of the input file" << std::endl;
		return -1;
	}
}
