#ifndef UTILITYLIBRARY_H
#define UTILITYLIBRARY_H

#include "ToolCommon.h"
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <windows.h>
#include <sstream>
#include <codecvt>
#include "../MyUtilityLibrary/CallConvention.h"

using namespace std;

 //Typedefs for function pointers
typedef void (*FnReverseString)(char*);
typedef void (*FnToUpperCase)(char*);
typedef void (*FnReadFromFile)(const char*);
typedef void (*FnWriteToFile)(const char*, const char*);

// Function to initialize and load DLL functions
bool initializeDLL(HMODULE& hLib, FnReverseString& reverseString, FnToUpperCase& toUpperCase, FnReadFromFile& readFromFile, FnWriteToFile& writeToFile);

// Function to execute DLL functions
void executeDLLFunctions(FnReverseString reverseString, FnToUpperCase toUpperCase, FnReadFromFile readFromFile, FnWriteToFile writeToFile);

// Function to display menu and handle user choices
void displayMenu(HMODULE& hLib, FnReverseString& reverseString, FnToUpperCase& toUpperCase, FnReadFromFile& readFromFile, FnWriteToFile& writeToFile);

// Main function to run the utility library application
void runUtilityLibraryApp();

void unloadDLL(HMODULE hLib);

void demonstrateCallingConventions();

#endif // UTILITYLIBRARY_H
