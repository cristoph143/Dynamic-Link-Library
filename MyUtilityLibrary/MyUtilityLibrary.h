// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MYUTILITYLIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MYUTILITYLIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "ToolCommon.h"

EXTERN_C_BEGIN

// Define function pointer types for the functions you expect to call from the DLL
typedef void (*FnReverseString)(char*);
typedef void (*FnToUpperCase)(char*);
typedef void (*FnReadFromFile)(const char*);
typedef void (*FnWriteToFile)(const char*, const char*);

typedef void(__cdecl* CDeclFunc)();
typedef void(__stdcall* StdCallFunc)();
typedef int(__stdcall* StdCallFuncWithParams)(int a, int b);
typedef void(__fastcall* FastCallFunc)();
typedef int(__fastcall* FastCallFuncWithParams)(int a, int b);
typedef HRESULT(__stdcall* SafeCallFunc)();


// Define Stdcall function
// Stdcall is a calling convention used by default in the Windows API.
// The callee is responsible for cleaning the stack after the function call.
// This convention is commonly used for Windows API functions.
MYUTILITYLIBRARY_API void __stdcall StdCallFunction() {
	PRINT_MESSAGE("Called StdCallFunction (stdcall)");
}

// Define Cdecl function
// Cdecl is a calling convention where the caller is responsible for cleaning the stack.
// It allows functions to accept variable argument lists (e.g., printf).
// This convention is often used for C++ functions.
MYUTILITYLIBRARY_API void __cdecl CDeclFunction() {
	PRINT_MESSAGE("Called CDeclFunction (cdecl)");
}

// Define Fastcall function
// Fastcall is a calling convention designed to speed up function calls by passing
// the first few arguments in registers rather than on the stack.
// It requires specific function signatures and compiler support.
// This convention can enhance performance for certain types of functions.
MYUTILITYLIBRARY_API void __fastcall FastCallFunction() {
	PRINT_MESSAGE("Called FastCallFunction (fastcall)");
}


MYUTILITYLIBRARY_API int __stdcall StdCallFunctionWithParams(int a, int b) {
    PRINT_MESSAGE("Called StdCallFunctionWithParams (stdcall) with a=%d, b=%d", a, b);
    return a + b;
}

MYUTILITYLIBRARY_API int __fastcall FastCallFunctionWithParams(int a, int b) {
    PRINT_MESSAGE("Called FastCallFunctionWithParams (fastcall) with a=%d, b=%d", a, b);
    return a - b;
}

MYUTILITYLIBRARY_API HRESULT __stdcall SafeCallFunction() {
    HRESULT result = E_FAIL;  // Example failure code
    PRINT_MESSAGE("Called SafeCallFunction (safecall) with result code: 0x%08X", result);
    return result;
}

MYUTILITYLIBRARY_API int nMyUtilityLibrary;
MYUTILITYLIBRARY_API int fnMyUtilityLibrary(void);
MYUTILITYLIBRARY_API void ReverseString(char* str);
MYUTILITYLIBRARY_API void ToUpperCase(char* str);
MYUTILITYLIBRARY_API void ReadFromFile(const char* filePath);
MYUTILITYLIBRARY_API void WriteToFile(const char* filePath, const char* content);

EXTERN_C_END

