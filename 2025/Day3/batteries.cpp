/**
 * @author Holden Kuempel
 * 
 * This program was developed to solve the 2025 Advent of Code Day 3, parts 1 and 2.
 * 
 * The challenge involves a series of battery packs. You need to maximize the voltage of each pack. In part one,
 * this is done by finding the largest 2 digit number within a string of numbers. The digits do not need to be 
 * adjacent, but the proper order must be perserved. Part two, is the same, you must create a 12-digit number.
 * The answer to each part of the puzzle is the sum of these highest possible voltages of each bank.
 * 
 * This program may take in an argument of 1 or 2. If it is provided it will only run that part of the challenge.
 * Otherwise, it will run both parts.
 * 
 * To complete this challenge yourself go to: https://adventofcode.com/2025/day/3
 */

#include "batteries.hpp"

ll sum; // This will the sum of all highest voltages for each part.

// partOne is solved with a brute force approach that tries each possible combination of two digit values for 
// each line.
ll partOne()
{
	sum = 0;
	std::string line;
	std::ifstream input ("input.txt");
	std::ofstream output ("logPart1.txt");
	if (input.is_open() && output.is_open())
	{
		output << "Battery Bank\n\tBank Max\n\n"; 
		while (getline(input, line))
		{
			output << line << std::endl;
			std::string tensPlace; // Placeholder for the tensplace for the battery voltage.
			std::string onesPlace; // Placeholder for the onesplace for the battery voltage.
			ll curMax = 0;
			for (ll i = 0; i < (ll) line.length() - 1; i++)
			{
				tensPlace = line.substr(i, 1);
				for (ll j = i + 1; j < (ll) line.length(); j++)
				{
					onesPlace = line.substr(j, 1);
					{
						ll temp = stoll(tensPlace + onesPlace);
						curMax = (temp > curMax) ? temp : curMax;
					}
				}
			}
			output << "\t" << curMax << std::endl << std::endl;
			sum += curMax;
		}
		input.close();
		output.close();
	}
	return sum;
}

// partTwo is solved with implementing a greedy algorithm that prioritizes the most significant digit to "min-max"
// the solution.
ll partTwo()
{
	sum = 0;
	std::string line;
	std::ifstream input ("input.txt");
	std::ofstream output ("logPart2.txt");
	if (input.is_open() && output.is_open())
	{
		output << "Battery Bank\n\tBank Max\n\n";
		while (getline(input, line))
		{
			output << line << std::endl;
			{
				ll temp = ptGreedy(line);
				output << "\t" << temp << std::endl << std::endl;
				sum += temp;
			}
		}
		input.close();
		output.close();
	}
	return sum;
}

ll ptGreedy(std::string line)
{
	ll hd = 0; // Highest Digit is the highest or largest digit within the current iteration 
	int hdic = -1; // The index at which the hd is found at the current iteration
	int hdip = -1; // The index at which the hd was found at the last iteration
	std::string numstr = ""; // The string which will contain the highest voltage.
	for (int i = 11; i >= 0; i--)
	{
		for (ll j = hdip + 1; j < (ll) line.length() - i; j++)
		{
			ll curDigit = (ll) (line.at(j) - '0');
			if (curDigit > hd)
			{
				hd = curDigit;
				hdic = j;
			}
		}
		numstr += std::to_string(hd);
		hdip = hdic;
		hd = 0;
	}
	return stoll(numstr);
}

int main(int argc, char* argv[])
{
	if (argc >= 2 && *argv[1] == '1')
	{
		std::cout << "Running just Part One" << std::endl;
		std::cout << "The total voltage: " << partOne() << std::endl;
		return 0;
	}
	else if (argc >= 2 && *argv[1] == '2')
	{
		std::cout << "Running just Part Two" << std::endl;
		std::cout << "The total voltage: " << partTwo() << std::endl;
		return 0;
	}
	else
	{
		std::cout << "The total voltage for Part One: " << partOne() << std::endl;
		std::cout << "The total voltage for Part Two: " << partTwo() << std::endl;
		return 0;
	}
}
