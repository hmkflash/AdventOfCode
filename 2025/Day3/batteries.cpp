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
