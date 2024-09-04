#pragma once

#ifdef MYUTILITYLIBRARY_EXPORTS
#define MYUTILITYLIBRARY_API __declspec(dllexport)
#else
#define MYUTILITYLIBRARY_API __declspec(dllimport)
#endif

using namespace std;
#include <fstream>    // For file operations
#include <string>     // For std::string
#include <cstring>    // For std::strlen, std::swap
#include <cctype>     // For std::toupper
#include <cstddef> // For size_t
#include <algorithm>
#include "extern_c.h"

#define PRINT_MESSAGE(format, ...) printf(format "\n", ##__VA_ARGS__)
#define PRINT_ERROR_MESSAGE(message) std::cerr << "Error: " << message << std::endl