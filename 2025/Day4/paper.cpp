#include "paper.hpp"

int count = 0;
std::vector<std::vector<char>> dataSet;

int main(int argc, char* argv[])
{
	if (argc >= 2 && *argv[1] == '1')
	{
		std::cout << "Running just Part One" << std::endl;
		std::cout << "Accessible rolls: " << partOne() << std::endl;
		return 0;
	}
	else if (argc >= 2 && *argv[1] == '2')
	{
		std::cout << "Running just Part Two" << std::endl;
		std::cout << "???: " << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Accessible rolls for Part One: " << partOne() << std::endl;
		std::cout << "???: " << std::endl;
		return 0;
	}
}

int partOne()
{
	parseData();
	if (dataSet.empty()) {return -1;}
	std::ofstream output ("logPart1.txt");
	if (output.is_open())
	{
		for (int y = 0; y < (int) dataSet.size(); y++)
		{
			for (int x = 0; x < (int) dataSet.at(y).size(); x++)
			{
				if (dataSet.at(y).at(x) == '.') {output << "."; continue;}
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

void parseData()
{
	if (dataSet.empty())
	{
		std::string line;
		std::ifstream input ("input.txt");
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
