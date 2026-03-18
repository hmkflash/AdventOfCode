#include "math.hpp"

vvull nums; // Each vector within nums contains the ints for a specific column or problem.
vc ops; // Contains the operation char for each problem.

void parseData(std::string inputName) {
	std::ifstream input (inputName);
	if (input.is_open()) {
		std::string line;
		while (getline(input, line)) {
			ull curProblem = 0; // The current index of the problem (or column).
			ull tempNum;
			char tempOp;
			std::stringstream ss(line);
			while (ss >> tempNum) {
				if (nums.empty() || nums.size() <= curProblem) {
					vull tempVec;
					tempVec.push_back(tempNum);
					nums.push_back(tempVec);
				} else {
					nums[curProblem].push_back(tempNum);	
				}
				curProblem++;
			} while (ss >> tempOp) {
				ops.push_back(tempOp);
			}
		}
		input.close();
	}
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
