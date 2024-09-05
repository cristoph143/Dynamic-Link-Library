#pragma once

#include <iostream>
#include <windows.h>
#include <map>
#include <string>
#include <sstream>

using namespace std;

#define PRINT_MESSAGE(format, ...) printf(format "\n", ##__VA_ARGS__)
#define PRINT_ERROR_MESSAGE(format, ...) \
    std::cerr << "Error: " << format << std::endl, __VA_ARGS__
// Function pointer typedefs for dynamic functions
typedef void (*MenuAction)();

// Struct to hold menu option description and associated action
struct MenuOption {
    string description;
    MenuAction action;
};

// Typedefs for function pointers
typedef void (*FnReverseString)(char*);
typedef void (*FnToUpperCase)(char*);
typedef void (*FnReadFromFile)(const char*);
typedef void (*FnWriteToFile)(const char*, const char*);

template<typename T>
T loadFunction(HMODULE hLib, const char* functionName) {
    // Get the address of the function
    auto function = reinterpret_cast<T>(GetProcAddress(hLib, functionName));
    if (!function) {
        cerr << "Failed to load function: " << functionName << endl;
    }
    return function;
}

//void runMenu(const map<int, MenuOption>& menuOptions);
void runMenu(const map<int, MenuOption>& menuOptions, int exitOption);

void exitApp();

string getStringInput(const std::string& prompt);

HMODULE loadDLL(const std::wstring& dllPath);
