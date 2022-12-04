#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>


std::istream_iterator<std::string> fIn(const char* fPath);
