#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <windows.h>

// Returns an iterator that can be used to iterate over the lines in the file
// at the given path.
//
// fPath: The path of the file to iterate over.
//
// Returns: An iterator for the file, or an empty iterator if the file could not
// be opened.
std::istream_iterator<std::string> string_IS_iter(const char* fPath);

std::vector<std::string> rFile_winapi(const char* fPath);
