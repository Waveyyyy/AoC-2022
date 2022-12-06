#include "Utilities.h"
#include "Challenges.h"

void DayOne_pt1()
{
	// Define a struct to store information about an elf
	struct elf {
		int num;		// The number of the elf
		int calories;	// The number of calories the elf is carrying
	};

	// Read the input file and store the lines in a vector of strings
	auto lines = rFile_winapi("Day1.txt");

	// Initialise a winner elf and current elf with default values
	elf winner{0,0};
	elf current{1,0};

	// Loop through the lines in the input file
	for (const auto& line : lines)
	{
		// Check if the current line is empty or contains only a CR and LF character
		if (line.empty() || line.find("\r\n") == 0 && line.size() == 2)
		{

			// Check if the current elf has more calories than the winner elf
			if ((winner.calories < current.calories) && (winner.num != current.num))
			{
				// If so, update the winner elf
				winner.num = current.num;
				winner.calories = current.calories;
			}

			// Increment the current elf number and reset the calories
			current.num += 1;
			current.calories = 0;
			
			// Continue to the next line
			continue;
		}

		// Parse the current line as an integer and add it to the current elf's carrying calories
		current.calories += std::atoi(line.c_str());

	}
	// Print the winner elf's number and number of calories they are carrying
	std::cout << "Winner is elf No." << winner.num << " with " << winner.calories << " calories" << std::endl;
}