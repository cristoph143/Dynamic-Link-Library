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

using namespace std;

// Global function pointers
extern FnReverseString reverseStringFunction;
extern FnToUpperCase toUpperCaseFunction;
extern FnReadFromFile readFromFileFunction;
extern FnWriteToFile writeToFileFunction;

typedef void(__cdecl* CDeclFunc)();
typedef void(__stdcall* StdCallFunc)();
typedef int(__stdcall* StdCallFuncWithParams)(int a, int b);
typedef void(__fastcall* FastCallFunc)();
typedef int(__fastcall* FastCallFuncWithParams)(int a, int b);
typedef HRESULT(__stdcall* SafeCallFunc)();


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
