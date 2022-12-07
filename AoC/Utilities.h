#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <windows.h>

/**
 * Reads a file with the given file path and returns an input stream iterator that can be used to
 * iterate over the lines in the file.
 *
 * @param fPath A null-terminated string containing the file path.
 * @return An input stream iterator that can be used to iterate over the lines in the file.
 * If the file could not be opened, an empty iterator is returned.
 */
std::istream_iterator<std::string> string_IS_iter(const char* fPath);

/**
 * Reads a file with the given file path and returns its contents as a vector of strings,
 * with each string representing a line in the file.
 *
 * @param fPath A null-terminated string containing the file path.
 * @return A vector of strings representing the lines in the file. If the file could not be opened,
 * an empty vector is returned.
 */
std::vector<std::string> rFile_winapi(const char* fPath);
