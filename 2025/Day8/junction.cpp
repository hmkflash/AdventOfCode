#include "junction.hpp"

// The vector of all Boxes;
std::vector<Box> allBoxes;

void constructBoxes(std::string inputName) {
	std::ifstream input (inputName);
	std::string line;
	if (input.is_open()) {
		while (getline(input, line)) {
			Box temp;
			size_t indexL = line.find(',');
			size_t indexR = line.find(',', indexL + 1);
			temp.x = std::stoull(line.substr(0, indexL));
			temp.y = std::stoull(line.substr(indexL + 1, indexR - (indexL + 1)));
			temp.z = std::stoull(line.substr(indexR + 1));
			allBoxes.push_back(temp);
		}
		input.close();
	}
}

std::vector<std::pair<Box, Box>> findNClosestPairs3d(std::vector<Box> Boxes, int numOfPairs) {
	std::sort(Boxes.begin(), Boxes.end(), [](Box a, Box b) {
		return a.x < b.x;
	});
	std::vector<Box> tempLeft;
	std::vector<Box> tempRight;
	for (auto& it = Boxes.begin)
}

ull partOne(std::string inputName) {
	constructBoxes(inputName);
	findNClosestPairs3d(allBoxes, 1000);
	return 0;
}

ull partTwo(std::string inputName) {
	constructBoxes(inputName);
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc >= 3 && *argv[2] == '1') {
		std::cout << "Running just Part One" << std::endl;
		std::cout << "Product of three largest circuits: " << partOne(argv[1]) << std::endl;
		return 0;
	} else if (argc >= 3 && *argv[2] == '2') {
		std::cout << "Running just Part Two" << std::endl;
		std::cout << "???: " << partTwo(argv[1]) << std::endl;
		return 0;
	} else if (argc >= 2) {
		std::cout << "Product of three largest circuits for Part One: " << partOne(argv[1]) << std::endl;
		std::cout << "??? for Part Two: " << partTwo(argv[1]) << std::endl;
		return 0;
	} else {	
		std::cerr << "No input file provided, first argument should be the name of the input file" << std::endl;
		return -1;
	}
}
