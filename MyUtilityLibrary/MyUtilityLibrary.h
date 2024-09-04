// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MYUTILITYLIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MYUTILITYLIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
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

#define PRINT_MESSAGE(format, ...) printf(format "\n", ##__VA_ARGS__)
#define PRINT_ERROR_MESSAGE(message) std::cerr << "Error: " << message << std::endl

// Define function pointer types for the functions you expect to call from the DLL
typedef void (*FnReverseString)(char*);
typedef void (*FnToUpperCase)(char*);
typedef void (*FnReadFromFile)(const char*);
typedef void (*FnWriteToFile)(const char*, const char*);

extern MYUTILITYLIBRARY_API int nMyUtilityLibrary;

extern "C" MYUTILITYLIBRARY_API int fnMyUtilityLibrary(void);

// Define Stdcall function
// Stdcall is a calling convention used by default in the Windows API.
// The callee is responsible for cleaning the stack after the function call.
// This convention is commonly used for Windows API functions.
extern "C" __declspec(dllexport) void __stdcall StdCallFunction() {
	PRINT_MESSAGE("Called StdCallFunction (stdcall)");
}

// Define Cdecl function
// Cdecl is a calling convention where the caller is responsible for cleaning the stack.
// It allows functions to accept variable argument lists (e.g., printf).
// This convention is often used for C++ functions.
extern "C" __declspec(dllexport) void __cdecl CDeclFunction() {
	PRINT_MESSAGE("Called CDeclFunction (cdecl)");
}

// Define Fastcall function
// Fastcall is a calling convention designed to speed up function calls by passing
// the first few arguments in registers rather than on the stack.
// It requires specific function signatures and compiler support.
// This convention can enhance performance for certain types of functions.
extern "C" __declspec(dllexport) void __fastcall FastCallFunction() {
	PRINT_MESSAGE("Called FastCallFunction (fastcall)");
}


// Additional utility function declarations
extern "C" {
	MYUTILITYLIBRARY_API void ReverseString(char* str);
	MYUTILITYLIBRARY_API void ToUpperCase(char* str);
	MYUTILITYLIBRARY_API void ReadFromFile(const char* filePath);
	MYUTILITYLIBRARY_API void WriteToFile(const char* filePath, const char* content);
}
