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
		output << "Battery Bank\t\t\t\t\t\t\t\t\t\t\t\tBank Max\n"; 
		while (getline(input, line))
		{
			output << line << "\t";
			std::string tensPlace = "0"; // Placeholder for the tensplace for the battery voltage.
			std::string onesPlace = "0"; // Placeholder for the onesplace for the battery voltage.
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
			output << curMax << std::endl;
			sum += curMax;
		}
	}
	return sum;
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
		std::cout << "The total voltage: " << "Still in progress" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "The total voltage for Part One: " << partOne() << std::endl;
		std::cout << "The total voltage for Part Two: " << "Still in progress" << std::endl;
		return 0;
	}
}
