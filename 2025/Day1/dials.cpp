/**
 * @author Holden Kuempel
 * 
 * This program was developed to solve the 2025 Advent of Code Day 1, parts 1 and 2. 
 * 
 * The challenge involves a dial with numbers 0-99 with a starting positionn of 50 and that can rotate Left or 
 * Right. Part One of the challenge wanted me to count the number of times that zero was the ending position after
 * an instruction. Part Two of the challenge wanted me to count the number of total times that zero was 
 * encountered during the instruction set.
 *
 * This program may take in an argument of 1 or 2. If it is provided it will only run that part of the challenge.
 * Otherwise, it will run both parts.
 *
 * To complete this challenge yourself go to: https://adventofcode.com/2025/day/1
 */

#include "dials.hpp"

int zeroCount = 0; // This is the number of times the dial has ended a rotation at zero.
int dialPlace = 50; // This is the location of the dial.

void reset()
{
	zeroCount = 0;
	dialPlace = 50;
}

int rotateDialOne(int distance) 
{
	if (distance == 0) 
	{
		// Base case: Dial doesn't rotate anymore and returns its final ending position.
		return dialPlace; 
	}
	else if (distance > 0)
	{
		if (dialPlace == 99)
		{
			// Edge case: Dial overflows, going from 99 to 0.
			dialPlace = 0;
		}
		else
		{
			// Typical case: Dial increments to the next position.
			dialPlace++;
		}
		// calls the function again, with the distance changing to account for movement it just made.
		return rotateDialOne(distance - 1); 
	}
	else if (distance < 0)
	{
		if (dialPlace == 0)
		{
			// Edge case: Dial underflows, going from 0 to 99.
			dialPlace = 99;
		}
		else
		{
			// Typical case: Dial deincrements to the next position.
			dialPlace--;
		}
		// calls the function again, with the distance changing to account for movement it just made.
		return rotateDialOne(distance + 1);
	}
	// This should never occur!
	return -1;
}

int rotateDialTwo(int distance)
{
	int count = 0; // The current count of zeroes for this instruction (used for logging info).
	if (distance < 0) 
	{
		// Iterates through the dial, based on the distance it needs to travel and in the correct direction, Left in this case.
		for (int i = distance; i < 0; i++)
		{
			if (dialPlace == 0) 
			{
				// Edge case: Dial underflows, going from 0 to 99.
				dialPlace = 99;
			}
			else
			{
				// Typical case: Dial deincrements to the next position.
				dialPlace--;
				if (dialPlace == 0)
				{
					// If current move of the dial moves it to a zero, count gets incremented.
					count++;
				}
			}
		}
		// Global variable gets incremented by the new count.
		zeroCount += count;
		return count; // Returns count
	}
	else if (distance > 0)
	{
		// Iterates through the dial, based on the distance it needs to travel and in the correct direct, Right in this case.
		for (int i = distance; i > 0; i--)
		{
			if (dialPlace == 99)
			{
				// Edge case: Dial overflows, going from 99 to 0.
				dialPlace = 0;
				// As this results in the dial reaching 0, the count gets incremented as well.
				count++;
			}
			else
			{
				// Typical case: Dial increments to the next position.
				dialPlace++;
			}
		}
		// Global variable get incremented by the new count.
		zeroCount += count;
		return count; // Returns count
	}
	else
	{
		// If the distance needed to travel is zero, then zero isn't passed. 
		return 0;
	}
}

// partOne is solved by incrementing dials one at a time, recursively. Checking after rotateDialOne is called to 
// see if it ends in o.
void partOne() 
{
	reset();
	std::string line; // The current line of iteration through the input.
	std::ifstream input ("input.txt"); // The input source for the program.
	std::ofstream output ("logPart1.txt"); // The output file for the program, which will contain each instruction that ends with the dial on zero.
	if (input.is_open() && output.is_open())
	{
		output << "instr." << "\t" << "end pos." << std::endl;
		while (getline (input, line)) 
		{
			char direction = line[0]; // The direction the dial needs to be moved for the current instruction.
			std::string lineDis = line.substr(1, line.length() - 1); // The subtring that is the distance for the current instruction.
			int distance = stoi(lineDis); // The distance the dial needs to be moved for the current instruction.
			if (direction == 'L')
			{
				distance *= -1; // If moving towards the left, the distance becomes negative.
			}
			if (rotateDialOne(distance) == 0) {
				zeroCount++;
			}
			if (abs((float) distance) > 99) 
			{
				output << line << "\t" << dialPlace << std::endl;
			}
			else
			{
				output << line << "\t\t" << dialPlace << std::endl;
			}
		}
	}
	input.close();
	output.close();
}

// partTwo is very similar to partOne, but the rotateDialsTwo function increments the zero count whenever zero is
// reached, not just when an instruction ends on a zero.
void partTwo()
{
	reset();
	std::string line; // The current line of iteration through the input.
	std::ifstream input ("input.txt"); // The input source for the program.
	std::ofstream output ("logPart2.txt"); // The output file for the program, which will contain each instruction and how many times it hits a zero.
	if (input.is_open() && output.is_open())
	{
		output << "instr." << "\t" << "end Pos." << "\t" << "cur. count" << "\t" << std::endl;
		while (getline (input, line))
		{
			char direction = line[0]; // The direction the dial needs to be moved for the current instruction.
			std::string lineDis = line.substr(1, line.length() - 1); // The substring that is the distance for the current instruction.
			int distance = stoi(lineDis); // The distance the dial needs to be moved for the current instruction.
			if (direction == 'L')
			{
				distance *= -1; // If moving towards the left, the distance becomes negative.
			}
			int currentCount = rotateDialTwo(distance);
			if (abs((float) distance) > 99)
			{
				output << line << "\t" << dialPlace << "\t\t\t" << currentCount << std::endl;
			}
			else
			{
				output << line << "\t\t" << dialPlace << "\t\t\t" << currentCount << std::endl;
			}
		}
	}
	input.close();
	output.close();
}

int main(int argc, char* argv[]) {
	if (argc >= 2 && *argv[1] == '1') 
	{
		std::cout << "Running Just Part One" << std::endl;
		partOne();
		std::cout << "Number of zeroes: " << zeroCount << std::endl;
		return 0;
	}
	else if (argc >= 2 && *argv[1] == '2')
	{
		std::cout << "Running Just Part Two" << std::endl;
		partTwo();
		std::cout << "Number of zeroes: " << zeroCount << std::endl;
		return 0;	
	}
	else
	{
		std::cout << "Running Both Parts" << std::endl;
		partOne();
		std::cout << "Number of zeroes for Part One: " << zeroCount << std::endl;
		partTwo();
		std::cout << "Number of zeroes for Part Two: " << zeroCount << std::endl;
		return 0;
	}
}
