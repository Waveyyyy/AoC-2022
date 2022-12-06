#include "Utilities.h"
#include "Challenges.h"

void DayOne()
{
	struct elf {
		int num;
		int calories;
	};

	auto lines = rFile_winapi("Day1.txt");
	elf winner{0,0};
	elf current{1,0};

	for (const auto& line : lines)
	{
		if (line.empty() || line.find("\r\n") == 0 && line.size() == 2)
		{

			if ((winner.calories < current.calories) && (winner.num != current.num))
			{
				winner.num = current.num;
				winner.calories = current.calories;
			}

			//std::cout << "elf No." << current.num << " has " << current.calories << " calories" << std::endl;
			//std::cout << "Current winner is elf No." << winner.num << " with " << winner.calories << " calories" << std::endl;
			current.num += 1;
			current.calories = 0;
			continue;
		}
		current.calories += std::atoi(line.c_str());

	}
	std::cout << "Winner is elf No." << winner.num << " with " << winner.calories << " calories" << std::endl;
}