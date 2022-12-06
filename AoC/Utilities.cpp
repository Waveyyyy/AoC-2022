#include "Utilities.h"

std::istream_iterator<std::string> getfIter(const char* fPath)
{
	// Open the file at the given path
	std::ifstream f{ fPath };

	// Check if the file was opened successfull
	if (f.is_open())
	{
		// Create an iterator for the file
		auto it = std::istream_iterator<std::string>{f};

		// Close the file and return the iterator
		f.close();
		return it;
	}
	// Print an error message and return an empty iterator
	std::cout << "Failed to open file " << fPath << std::endl;
	return std::istream_iterator<std::string>{};
}
