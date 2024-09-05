// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MYUTILITYLIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MYUTILITYLIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "ToolCommon.h"

// Define function pointer types for the functions you expect to call from the DLL
EXTERN_C_BEGIN

typedef void (*FnReverseString)(char*);
typedef void (*FnToUpperCase)(char*);
typedef void (*FnReadFromFile)(const char*);
typedef void (*FnWriteToFile)(const char*, const char*);

MYUTILITYLIBRARY_API int nMyUtilityLibrary;
MYUTILITYLIBRARY_API int fnMyUtilityLibrary(void);
MYUTILITYLIBRARY_API void ReverseString(char* str);
MYUTILITYLIBRARY_API void ToUpperCase(char* str);
MYUTILITYLIBRARY_API void ReadFromFile(const char* filePath);
MYUTILITYLIBRARY_API void WriteToFile(const char* filePath, const char* content);

EXTERN_C_END

