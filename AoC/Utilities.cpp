#include "Utilities.h"

std::istream_iterator<std::string> string_IS_iter(const char* fPath)
{
	// Open the file with the given path
	std::ifstream f{ fPath };

	// Check if the file was successfully opened
	if (f.is_open())
	{
		// Create an input stream iterator that can be used 
		// to iterate over the lines in the file
		auto it = std::istream_iterator<std::string>{f};

		// Close the file and return the iterator
		f.close();
		return it;
	}
	// Print an error message and return an empty iterator
	std::cout << "Failed to open file " << fPath << std::endl;
	return std::istream_iterator<std::string>{};
}

std::vector<std::string> rFile_winapi(const char* fPath)
{
	// Convert the file path to a wide string, as required by the Windows API
	std::wstring wfPath(fPath, fPath + strlen(fPath));
	LPCWSTR lpfPath = wfPath.c_str();

	// Open the file with the given file path
	HANDLE fHandle = CreateFile(lpfPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);

	// Check if the file was successfully opened
	if (fHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "Failed to open the file!" << std::endl;
		return std::vector<std::string>{};
	}

	// Read the file contents
	std::string line;	// Buffer to hold the read data
	char c;				// Stores current character
	DWORD bRead;		// Number of bytes actually read
	std::vector<std::string> lines;
	
	while (ReadFile(fHandle, &c, sizeof(c), &bRead, NULL) && bRead > 0)
	{
		line.push_back(c);
		if (c != '\r')
		{
			continue;
		}
		if (ReadFile(fHandle, &c, sizeof(c), &bRead, NULL) && bRead > 0)
		{
			line.push_back(c);
			if (c != '\n')
			{
				continue;
			}
			lines.push_back(line);
			line.clear();
		}
	}
	CloseHandle(fHandle);

	return lines;
}
