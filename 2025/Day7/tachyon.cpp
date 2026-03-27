#include "tachyon.hpp"

// First is the index that a particular tachyon is located.
// Second is the timeline weight of a particular tachyon.
std::vector<std::pair<size_t, ull>> laserPos;
ull total1 = 0; // Keeps track of the number of times the beam is split.
ull total2 = 0; // Totals the number of individual timelines.

void condense(std::vector<std::pair<size_t, ull>> &lasers) {
	for (size_t i = 0; i < lasers.size() - 1; i++) {
		if (lasers[i].first == lasers[i + 1].first) {
			lasers[i].second += lasers[i + 1].second;
			lasers.erase(lasers.begin() + 1 + i);
			i--;
		}
	}
}


void sort(std::vector<std::pair<size_t, ull>> &lasers) {
	for (int i = 1; i < (int) lasers.size(); i++) {
		std::pair<size_t, ull> cur = lasers[i];
		int j = i - 1;
		while (j >= 0 && lasers[j].first > cur.first) {
			lasers[j + 1] = lasers[j];
			j--;
		}
		lasers[j + 1] = cur;
	}
	/*
	std::sort(laserPos.begin(), laserPos.end(), [](std::pair<size_t, ull> a, std::pair<size_t, ull> b){
		return (a.first <= b.first);
	});
	*/
	condense(lasers);
}


void solveProblem(std::string inputName) {
	std::ifstream input (inputName);
	std::ofstream outVis ("logVisual.txt");
	std::ofstream outPos ("logPositions.txt");
	if (input.is_open() && outVis.is_open() && outPos.is_open()) {
		std::string line;
		while (getline(input, line)) {
			// Checks if the current row is a logging row
			if (line.find('^') == std::string::npos && line.find('S') == std::string::npos) {
				for (auto it = laserPos.begin(); it != laserPos.end(); it++) {
					line[it->first] = '|';
				}
			} else if (line.find('S') != std::string::npos) { // Checks if this is the first row of input.
				std::pair<size_t, ull> temp;
				temp.first = line.find('S');
				temp.second = 1;
				laserPos.push_back(temp);
			} else {
				size_t index = 0;
				std::vector<std::pair<size_t, ull>> newLasers;
				while (line.find('^', index) != std::string::npos) {
					size_t foundPos = line.find('^', index); 
					for (auto it = laserPos.begin(); it != laserPos.end(); it++) {
						if (it->first == foundPos) {
							it->first -= 1;
							std::pair<size_t, ull> temp;
							temp.first = it->first + 2;
							temp.second = it->second;
							newLasers.push_back(temp);
							//line[foundPos - 1] = '|';
							//line[foundPos + 1] = '|';
							//index = foundPos + 1;
							total1++;
							break;
						}
					}
					index = foundPos + 1;
				}
				for (auto it = newLasers.begin(); it != newLasers.end(); it++) {
					laserPos.push_back(*it);
				}
				sort(laserPos);
				for (auto it = laserPos.begin(); it != laserPos.end(); it++) {
					line[it->first] = '|';
				}
			}
			outVis << line << std::endl;
			for (auto it = laserPos.begin(); it != laserPos.end(); it++) {
				outPos << '(' << it->first << ", " << it->second << "), "; 
			}
			outPos << std::endl;
		}
		for (auto it = laserPos.begin(); it != laserPos.end(); it++) {
			total2 += it->second;
		}
		input.close();
		outVis.close();
	}
}

int main(int argc, char* argv[]) {
	if (argc >= 3 && *argv[2] == '1') {
		solveProblem(argv[1]);
		std::cout << "Running just Part One" << std::endl;
		std::cout << "Total sum of problems: " << total1 << std::endl;
		return 0;
	} else if (argc >= 3 && *argv[2] == '2') {
		solveProblem(argv[1]);
		std::cout << "Running just Part Two" << std::endl;
		std::cout << "Total sum of problems: " << total2 << std::endl;
		return 0;
	} else if (argc >= 2) {
		solveProblem(argv[1]);
		std::cout << "Total sum of problems for Part One: " << total1 << std::endl;
		std::cout << "Total sum of problems for Part Two: " << total2 << std::endl;
		return 0;
	} else {	
		std::cerr << "No input file provided, first argument should be the name of the input file" << std::endl;
		return -1;
	}
}
