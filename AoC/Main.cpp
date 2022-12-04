#include <iostream>
#include <string>
#include <vector>
#include "Utilities.h"

int main()
{
	std::vector<std::string> file{ fIn("Day1.txt")};

	for (const std::string& line : file)
	{
		std::cout << line << std::endl;
	}

	return 0;
}