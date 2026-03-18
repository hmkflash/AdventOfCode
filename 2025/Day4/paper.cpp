/**
 * @author Holden Kuempel
 * 
 * This program was developed to solve the 2025 Advent of Code Day 4, parts 1 and 2.
 * 
 * The challenge involves a warehouse of paper rolls. A roll cannot be cleared if it is adjacent to 4 or more 
 * other rolls. In part one, only the rolls that can be immediately removed are. In part two, this process is 
 * repeated until no additional rolls can be removed.
 * 
 * This program may take in an argument of 1 or 2. If it is provided it will only run that part of the challenge.
 * Otherwise, it will run both parts.
 * 
 * To complete this challenge yourself go to: https://adventofcode.com/2025/day/4
 */
#include "paper.hpp"

// dataSet is a vector of vectors containing the individual chars of the data.
std::vector<std::vector<char>> dataSet;

// dataSet copies the data of the inputName file into a format that can be more easily accessed.
void parseData(std::string inputName)
{
	dataSet.clear();
	if (dataSet.empty())
	{
		std::string line;
		std::ifstream input (inputName);
		if (input.is_open())
		{
			while (getline(input, line))
			{
				std::vector<char> tempVector;
				for (int i = 0; i < (int) line.length(); i++)
				{
					tempVector.push_back(line.at(i));
				}
				dataSet.push_back(tempVector);
			}
			input.close();	
		}
	}
}

// This function will iterate through the dataSet and count the number of rolls of paper that can be moved based 
// on its curent state. The parameter log is the name of the log file generated, which will show an 'X' in each
// spot that a roll was removed, a '.' in each spot that was initally lacking a roll, and a '@' in each spot 
// where a roll couldn't be moved. 
int parseOneRound(std::string log)
{
	unsigned long long count = 0;
 	if (dataSet.empty()) {return -1;}
	std::ofstream output (log);
	if (output.is_open())
	{
		for (int y = 0; y < (int) dataSet.size(); y++)
		{
			for (int x = 0; x < (int) dataSet.at(y).size(); x++)
			{
				if (dataSet.at(y).at(x) != '@') {output << "."; continue;}
				if (x == 0)
				{
					if (y == 0)
					{
						output << "x";
						count++;
					}
					else if (y == (int) dataSet.size() - 1)
					{
						output << "x";
						count++;
					}
					else
					{
						int temp = 0;
						temp += (dataSet.at(y-1).at(x) == '@') ? 1 : 0; // Checks top
						temp += (dataSet.at(y-1).at(x+1) == '@') ? 1 : 0; // Checks top right
						temp += (dataSet.at(y).at(x+1) == '@') ? 1 : 0; // Checks right
						temp += (dataSet.at(y+1).at(x+1) == '@') ? 1 : 0; // Checks bottom right
						temp += (dataSet.at(y+1).at(x) == '@') ? 1 : 0; // Checks bottom
						if (temp < 4)
						{
							output << "x";
							count++;
						}
						else
						{
							output << "@";
						}
					}
				}
				else if (x == (int) dataSet.at(y).size() - 1)
				{
					if (y == 0)
					{
						output << "x";
						count++;
					}
					else if (y == (int) dataSet.size() - 1)
					{
						output << "x";
						count++;
					}
					else
					{
						int temp = 0;
						temp += (dataSet.at(y+1).at(x) == '@') ? 1 : 0; // Checks bottom
						temp += (dataSet.at(y+1).at(x-1) == '@') ? 1 : 0; // Checks bottom left
						temp += (dataSet.at(y).at(x-1) == '@') ? 1 : 0; // Checks left
						temp += (dataSet.at(y-1).at(x-1) == '@') ? 1 : 0; // Checks top left
						temp += (dataSet.at(y-1).at(x) == '@') ? 1 : 0; // Checks top
						if (temp < 4)
						{
							output << "x";
							count++;
						}
						else
						{
							output << "@";
						}					
					}
				}
				else
				{
					if (y == 0)
					{
						int temp = 0;
						temp += (dataSet.at(y).at(x+1) == '@') ? 1 : 0; // Checks right
						temp += (dataSet.at(y+1).at(x+1) == '@') ? 1 : 0; // Checks bottom right
						temp += (dataSet.at(y+1).at(x) == '@') ? 1 : 0; // Checks bottom
						temp += (dataSet.at(y+1).at(x-1) == '@') ? 1 : 0; // Checks bottom left
						temp += (dataSet.at(y).at(x-1) == '@') ? 1 : 0; // Checks left
						if (temp < 4)
						{
							output << "x";
							count++;
						}
						else
						{
							output << "@";
						}
					}
					else if (y == (int) dataSet.size() - 1)
					{
						int temp = 0;
						temp += (dataSet.at(y).at(x-1) == '@') ? 1 : 0; // Check left
						temp += (dataSet.at(y-1).at(x-1) == '@') ? 1 : 0; // CHeck top left
						temp += (dataSet.at(y-1).at(x) == '@') ? 1 : 0; // Check top
						temp += (dataSet.at(y-1).at(x+1) == '@') ? 1 : 0; // Check top right
						temp += (dataSet.at(y).at(x+1) == '@') ? 1 : 0; // Check right
						if (temp < 4)
						{
							output << "x";
							count++;
							
						}
						else
						{
							output << "@";
						}
					}
					else
					{
						int temp = 0;
						temp += (dataSet.at(y-1).at(x) == '@') ? 1 : 0; // Checks top
						temp += (dataSet.at(y-1).at(x+1) == '@') ? 1 : 0; // Checks top right
						temp += (dataSet.at(y).at(x+1) == '@') ? 1 : 0; // Checks right
						temp += (dataSet.at(y+1).at(x+1) == '@') ? 1 : 0; // Checks bottom right
						temp += (dataSet.at(y+1).at(x) == '@') ? 1 : 0; // Checks bottom
						temp += (dataSet.at(y+1).at(x-1) == '@') ? 1 : 0; // Checks bottom left
						temp += (dataSet.at(y).at(x-1) == '@') ? 1 : 0; // checks left
						temp += (dataSet.at(y-1).at(x-1) == '@') ? 1 : 0; // Checks top left
						if (temp < 4)
						{
							output << "x";
							count++;
							
						}
						else
						{
							output << "@";
						}
					}
				}
			}
			output << "\t" << count << std::endl;
		}
		output.close();
	}
	return count;
}

int partOne(std::string inputName)
{
	parseData(inputName);
	return parseOneRound("logPart1.txt");
}

int partTwo(std::string inputName)
{
	unsigned long long count = 0; // Total number of rolls removed.
	parseData(inputName);
	std::string logRoot = "logPart2-";
	int countOfCalls = 1; // Kept track of for the sake of log tracking.
	std::string logPrefix = ".txt";
	int updatedCount = parseOneRound(logRoot + std::to_string(countOfCalls) + logPrefix);
	count += updatedCount; // updatedCount is the number of rolls removed after the most recent iteration.
	while (updatedCount > 0) // Runs until nothing can be removed.
	{
		parseData(logRoot + std::to_string(countOfCalls) + logPrefix);
		countOfCalls++;
		updatedCount = parseOneRound(logRoot + std::to_string(countOfCalls) + logPrefix);
		count += updatedCount;
	}
	return count;
}

int main(int argc, char* argv[])
{
	if (argc >= 3 && *argv[2] == '1')
	{
		std::cout << "Running just Part One" << std::endl;
		std::cout << "Accessible rolls: " << partOne(argv[1]) << std::endl;
		return 0;
	}
	else if (argc >= 3 && *argv[2] == '2')
	{
		std::cout << "Running just Part Two" << std::endl;
		std::cout << "Accessible rolls: " << partTwo(argv[1]) << std::endl;
		return 0;
	}
	else if (argc >= 2)
	{
		std::cout << "Accessible rolls for Part One: " << partOne(argv[1]) << std::endl;
		std::cout << "Accessible rolls for Part Two: " << partTwo(argv[1]) << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "No input file provided, first argument should be the name of the input file" << std::endl;
		return -1;
	}
}
