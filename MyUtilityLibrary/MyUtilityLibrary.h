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

// Define function pointer types for the functions you expect to call from the DLL
typedef void (*FnReverseString)(char*);
typedef void (*FnToUpperCase)(char*);
typedef void (*FnReadFromFile)(const char*);
typedef void (*FnWriteToFile)(const char*, const char*);

// This class is exported from the dll
//class MYUTILITYLIBRARY_API CMyUtilityLibrary {
//public:
//	CMyUtilityLibrary(void);
//	void ReverseString(char* str);
//	void ToUpperCase(char* str);
//	void ReadFromFile(const char* filePath);
//	void WriteToFile(const char* filePath, const char* content);
//};

extern MYUTILITYLIBRARY_API int nMyUtilityLibrary;

extern "C" MYUTILITYLIBRARY_API int fnMyUtilityLibrary(void);

// Additional utility function declarations
extern "C" {
	MYUTILITYLIBRARY_API void ReverseString(char* str);
	MYUTILITYLIBRARY_API void ToUpperCase(char* str);
	MYUTILITYLIBRARY_API void ReadFromFile(const char* filePath);
	MYUTILITYLIBRARY_API void WriteToFile(const char* filePath, const char* content);
}
