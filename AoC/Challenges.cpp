#include "Utilities.h"
#include "Challenges.h"

void DayOne()
{
	std::istream_iterator<std::string> file = getfIter("Day1.txt");



	while (file != std::istream_iterator<std::string>{})
	{

		std::cout << *file << std::endl;
			
		file++;

	}
}