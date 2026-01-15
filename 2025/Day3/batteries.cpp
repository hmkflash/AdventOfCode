#include "batteries.hpp"

ll sum;

ll partOne()
{
	sum = 0;
	std::string line;
	std::ifstream input ("input.txt");
	std::ofstream output ("logPart1.txt");
	if (input.is_open() && output.is_open())
	{
		
	}
}

int main(int argc, char* argv[])
{
	if (argc >= 2 && *argv[1] == '1')
	{
		std::cout << "Running just Part One" << std::endl;
		return 0;
	}
	else if (argc >= 2 && *argv[1] == '2')
	{
		std::cout << "Running just Part Two" << std::endl;
		return 0;
	}
	else
	{
		return 0;
	}
}
