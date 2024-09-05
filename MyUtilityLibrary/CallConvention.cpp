#include "CallConvention.h"
#include <cstdio>
#include "ToolCommon.h"
#include <winerror.h>
#include "pch.h"
#include <stdio.h>

#define PRINT_MESSAGE(format, ...) printf(format "\n", ##__VA_ARGS__)

 void __cdecl CDeclFunction() {
    PRINT_MESSAGE("Called CDeclFunction (cdecl)");
}

 void __stdcall StdCallFunction() {
    PRINT_MESSAGE("Called StdCallFunction (stdcall)");
}

 int __stdcall StdCallFunctionWithParams(int a, int b) {
    PRINT_MESSAGE("Called StdCallFunctionWithParams (stdcall) with a=%d, b=%d", a, b);
    return a + b;
}

 void __fastcall FastCallFunction() {
    PRINT_MESSAGE("Called FastCallFunction (fastcall)");
}

 int __fastcall FastCallFunctionWithParams(int a, int b) {
    PRINT_MESSAGE("Called FastCallFunctionWithParams (fastcall) with a=%d, b=%d", a, b);
    return a - b;
}

 HRESULT __stdcall SafeCallFunction() {
    HRESULT result = E_FAIL;  // Example failure code
    PRINT_MESSAGE("Called SafeCallFunction (safecall) with result code: 0x%08X", result);
    return result;
}