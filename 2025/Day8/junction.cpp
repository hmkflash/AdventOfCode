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

std::vector<ClosePair> findNClosestPairs3d(std::vector<Box>::iterator first, std::vector<Box>::iterator last, size_t n, size_t numOfPairs) {
	if (n == 2) {
		std::vector<ClosePair> vTemp;
		ClosePair pTemp;
		pTemp.distance = abs(
			((first+1)->x - first->x) * ((first+1)->x - first->x) +
			((first+1)->y - first->y) * ((first+1)->y - first->y) +
			((first+1)->z - first->z) * ((first+1)->z - first->z)
		); 
		// Distance calculate is techincally incorrect as it doesn't sqrt, but since no junction boxes are on 
		// top of each other and input is in ints the minimum distance between two junctions is 1 and so even 
		// if the distance is technically incorrect when comparing these distances to each other it is still 
		// correct.
		pTemp.a = *first;
		pTemp.b = *(first+1);
		vTemp.push_back(pTemp);
		return vTemp;
	}
	std::vector<ClosePair> leftPart = findNClosestPairs3d(first, first + (n/2) + 1, (n/2) + 1, numOfPairs);
	std::vector<ClosePair> rightPart = findNClosestPairs3d(first + (n/2), last, (n/2) + (n%2), numOfPairs);
	std::vector<ClosePair> fullPart;
	size_t l = 0;
	size_t r = 0;
	while (fullPart.size() < numOfPairs) {
		if (l >= leftPart.size() && r >= rightPart.size()) {
			break;
		} else if (l >= leftPart.size()) {
			fullPart.push_back(rightPart[r]);
			r++;
		} else if (r >= rightPart.size()) {
			fullPart.push_back(leftPart[l]);
			l++;
		} else if (leftPart[l].distance <= rightPart[r].distance) {
			fullPart.push_back(leftPart[l]);
			l++;
		} else {
			fullPart.push_back(rightPart[r]);
			r++;
		}
	}
	return fullPart;
}

ull partOne(std::string inputName) {
	constructBoxes(inputName);
	// Sorts this segment of the data
	std::sort(allBoxes.begin(), allBoxes.end(), [](Box a, Box b) {
		return a.x < b.x;
	});
	std::vector<ClosePair> closestPairs = findNClosestPairs3d(allBoxes.begin(), allBoxes.end(), allBoxes.size(), 1000);
	for (auto& elem : closestPairs) {
		std::cerr << "Distance: " << elem.distance << ".\nPair A = {" << elem.a.x << ", " << elem.a.y << ", " << 
				elem.a.z << "}.\nPair B = {" << elem.b.x << ", " << elem.b.y << ", " << elem.b.z << "}.\n\n";
	}
	std::cerr << "Num of pairs: " << closestPairs.size() << std::endl;
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
