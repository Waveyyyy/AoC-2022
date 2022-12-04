#include <iostream>
#include <fstream>
#include <string>

#include "Utilities.h"

void fIn(const char* fPath)
{
	std::ifstream f{ fPath };

	if (!f.is_open())
	{
		std::cout << "Failed to open file" << fPath << std::endl;
		return;
	}

	std::string line;
	while (std::getline(f, line))
	{
		std::cout << line << std::endl;
	}

	f.close();
}
