#include "ids.hpp"

void partOne()
{
	std::string line;
	std::ifstream input ("input.txt");
	std::ofstream output ("logPart1.txt");
	if (input.is_open() && output.is_open())
	{
		while (std::getline(input, line))
		{
			while (!line.empty())
			{
				int dashIndex = line.find('-');
				// The index at which the "," is located or after the last char.
				int commaIndex; {int temp = line.find(','); commaIndex = (temp != (int) std::string::npos) ? temp : line.length();} 
				std::string minstr = line.substr(0, dashIndex - 1);
				std::string maxstr = line.substr(dashIndex + 1, commaIndex - dashIndex - 1);
				int min = stoi(minstr); int max = stoi(maxstr);
				line.erase(0, commaIndex);
				if (line.find(',') == 0) {line.erase(0, 1);}
				int curID = 0; // The ID that will be verified as valid ot invalid.
				// i is the number of digits for which we are repeating.
				for (int i = minstr.length() / 2; curID <= max; i++)
				{
					// j is the iterator for each possible invalid id.	
					for (int j = (int) (pow(10, i - 1)); j < (int) (pow(10, i) - 1); j++)
					{
						std::string idsubstr = std::to_string(j); // Converts j into a string.
						std::string idstr = idsubstr + idsubstr; // Conconates the substrings together.
						curID = stoi(idstr); // Creates an invalid id, that may be within the range in question.
					}
				}
			}
		}
	}
	input.close();
	output.close();
}

int main()
{
	partOne();
	return 1;
}
