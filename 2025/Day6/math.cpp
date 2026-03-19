/**
 * @author Holden Kuempel
 * 
 * This program was developed to solve the 2025 Advent of Code Day 6, parts 1 and 2.
 * 
 * The challenge involves a series of math puzzles written in a unique and problematic format. They are listed in
 * groups of vertical columns with an operation (+) or (*) below. The goal is to perform the provided operation on
 * the group and sum of all result of those problems. In part one, it is assumed that the numbers are listed 
 * horizontally, while in part two it is understood that the numbers are actually listed in vertical columns.
 * 
 * This program requires the name of an input file as the first argument and may take in an argument of 1 or 2. If 
 * it is provided it will only run that part of the challenge. Otherwise, it will run both parts.
 * 
 * To complete this challenge yourself go to: https://adventofcode.com/2025/day/6
 */

#include "math.hpp"

std::vector<std::vector<ull>> nums; // Each vector within nums contains the ints for a specific column or problem.
std::vector<char> ops; // Contains the operation char for each problem.

// Iterates over each line of data adding it to its correct problem set, putting ulls into a sub-vector of nums 
// and putting the operations into ops. It does this by using a stringstream and checking the length of each 
// value before using its length to determine whether it is a num or an op.
void parseDataPartOne(std::string inputName) {
	std::ifstream input (inputName);
	if (input.is_open()) {
		std::string line;
		while (getline(input, line)) {
			ull curProblem = 0; // The current index of the problem (or column).
			std::stringstream ss(line);
			std::string temp;
			while (ss >> temp) {
				if (temp.length() == 1 && (temp[0] == '*' || temp[0] == '+')) {
					ops.push_back(temp[0]);
				} else {
					// If nums has space for the current problem.
					if (nums.empty() || curProblem >= nums.size()) {
						std::vector<ull> tempVec;
						tempVec.push_back(std::stoull(temp));
						nums.push_back(tempVec);
					} else {
						nums[curProblem].push_back(std::stoull(temp));
					}
				}
				curProblem++;
			}
		}			
		input.close();
	}
}

// The data parsing for part two is a little different. Each column represents a single number and there is the 
// potiental for additional white space as well. This data gets parsed by storing each line of data at the very 
// beginning and parsing horizontally rather than vertically. I use the placement of the operations as a 
// grounding for the potential length of the ints being parsed. I then parse the ints into an array of chars 
// treating white spaces as a 0 before converting that array into a ull with a stoull call. Special handling is
// done for the last piece of data as each line has the potienal to end on a different value so instead of using
// the next op as the ground I use the maximum length of the intLines.
void parseDataPartTwo(std::string inputName) {
	nums.clear();
	ops.clear();
	std::ifstream input (inputName);
	if (input.is_open()) {
		std::string intLines[4];
		std::string opLine;
		// Gets all the int data
		for (int i = 0; i < 4; i++) {
			getline(input, intLines[i]);
		}
		getline(input, opLine);
		int index = 0;
		while (index < (int) opLine.length()) { // Each iteration tackles one math problem.
			char curOp = opLine[index];
			ops.push_back(curOp);
			opLine[index] = 0;
			int nextIndex;
			// Checks if this is the last operation
			if (opLine.find('+') == std::string::npos && opLine.find('*') == std::string::npos) {
				// scope here so that temp1 and temp2 can be forgotten about
				{
					int temp1 = (intLines[0].length() >= intLines[1].length()) ? intLines[0].length() : intLines[1].length();
					int temp2 = (intLines[2].length() >= intLines[3].length()) ? intLines[2].length() : intLines[3].length();
					// nextIndex is set to the highest length of the intLines.
			 		nextIndex = (temp1 >= temp2) ? temp1 : temp2;	
				}
				std::vector<ull> tempVec;
				// Iterates through each column of the current problem.
				for (int i = nextIndex - 1; i >= index; i--) { 
					std::string numChar = "";
					// Iterates through each row of the current int
					for (int j = 0; j < 4; j++) {
						// Checks if i is indexing beyond the range of intLines[j] or if it is whitespace. 
						if (i < (int) intLines[j].length() &&  intLines[j][i] != ' ') {
							numChar += intLines[j][i];
						}
					}
					tempVec.push_back(std::stoull(numChar));
				}
				nums.push_back(tempVec);
			} else { // This is not the last operation
				nextIndex = (opLine.find('+') < opLine.find('*')) ? opLine.find('+') : opLine.find('*');
				std::vector<ull> tempVec;
				// Iterates through each column of the current problem.
				for (int i = nextIndex - 2; i >= index; i--) {
					std::string numChar = "";
					// Iterates through each row of the current int
					for (int j = 0; j < 4; j++) {
						// checks if intLines[j][i] contains whitespace
						if (intLines[j][i] != ' ') {
							numChar += intLines[j][i];
						}
					}
					tempVec.push_back(std::stoull(numChar));
				}
				nums.push_back(tempVec);
			}
			index = nextIndex;
		}
		input.close();
	}
}

// Takes in the setof numbers for a problem and that problems operator and calculates, then returns, the sum or 
// multiplication of all values within the problem set.
ull solveProblem(std::vector<ull>  numSet, char op) {
	if (op == '+') {
		ull temp = 0;
		for (auto it = numSet.begin(); it != numSet.end(); it++) {
			temp += *it;
		}
		return temp;
	} else {
		ull temp = 1;
		for (auto it = numSet.begin(); it != numSet.end(); it++) {
			temp *= *it;
		}
		return temp;
	}
}

ull partOne(std::string inputName)
{
	parseDataPartOne(inputName);
	ull total = 0;
	std::ofstream output ("logPart1.txt");
	if (output.is_open()) {
		for (ull i = 0; i < ops.size(); i++) {
			ull temp = solveProblem(nums[i], ops[i]);
			output << "Problem " << i << ": " << temp << "\tOperation: " << ops[i] << std::endl;
			total += temp;
		}
		output.close();		
	}
	return total;
}

ull partTwo(std::string inputName) {
	parseDataPartTwo(inputName);
	ull total = 0;
	std::ofstream output ("logPart2.txt");
	if (output.is_open()) {
		for (ull i = 0; i < ops.size(); i++) {
			ull temp = solveProblem(nums[i], ops[i]);
			output << "Problem " << i << ": " << temp << "\tOperation: " << ops[i] << std::endl;
			total += temp;
		}
		output.close();
	}
	return total;
}

int main(int argc, char* argv[]) {
	if (argc >= 3 && *argv[2] == '1') {
		std::cout << "Running just Part One" << std::endl;
		std::cout << "Total sum of problems: " << partOne(argv[1]) << std::endl;
		return 0;
	} else if (argc >= 3 && *argv[2] == '2') {
		std::cout << "Running just Part Two" << std::endl;
		std::cout << "Total sum of problems: " << partTwo(argv[1]) << std::endl;
		return 0;
	} else if (argc >= 2) {
		std::cout << "Total sum of problems for Part One: " << partOne(argv[1]) << std::endl;
		std::cout << "Total sum of problems for Part Two: " << partTwo(argv[1]) << std::endl;
		return 0;
	} else {	
		std::cerr << "No input file provided, first argument should be the name of the input file" << std::endl;
		return -1;
	}
}
