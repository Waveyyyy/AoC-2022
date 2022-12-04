#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Utilities.h"

std::vector<std::string> fIn(const char* fPath)
{
	std::ifstream f{ fPath };

	if (!f.is_open())
	{
		std::cout << "Failed to open file " << fPath << std::endl;
		f.close();
		return std::vector<std::string>{};
	}
	std::vector<std::string> lines;
	std::string line;

	while (std::getline(f, line))
	{
		lines.push_back(line);
	}

	f.close();
	return lines;
}
