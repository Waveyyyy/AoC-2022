#include "Utilities.h"

std::istream_iterator<std::string> fIn(const char* fPath)
{
	std::ifstream f{ fPath };

	if (!f.is_open())
	{
		std::cout << "Failed to open file " << fPath << std::endl;
		return std::istream_iterator<std::string>{};
	}
	return std::istream_iterator<std::string>{f};
}
