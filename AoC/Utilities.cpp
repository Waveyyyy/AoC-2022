#include "Utilities.h"

std::istream_iterator<std::string> string_IS_iter(const char* fPath)
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

std::vector<std::string> rFile_winapi(const char* fPath)
{
	std::wstring wfPath(fPath, fPath + strlen(fPath));
	LPCWSTR lpfPath = wfPath.c_str();

	HANDLE fHandle = CreateFile(lpfPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);

	if (fHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "Failed to open the file!" << std::endl;
		return std::vector<std::string>{};
	}

	char buf[1024];
	DWORD bRead;
	std::vector<std::string> lines;
	
	while (ReadFile(fHandle, buf, sizeof(buf), &bRead, NULL) && bRead > 0)
	{
		lines.push_back(std::string(buf, bRead));
	}
	CloseHandle(fHandle);

	return lines;
}
