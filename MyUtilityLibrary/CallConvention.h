#pragma once
#ifndef CALLCONVENTION_H
#define CALLCONVENTION_H

#include "ToolCommon.h"
#include "extern_c.h"
#include <windows.h>

typedef void(__cdecl* CDeclFunc)();
typedef void(__stdcall* StdCallFunc)();
typedef int(__stdcall* StdCallFuncWithParams)(int a, int b);
typedef void(__fastcall* FastCallFunc)();
typedef int(__fastcall* FastCallFuncWithParams)(int a, int b);
typedef HRESULT(__stdcall* SafeCallFunc)();

EXTERN_C_BEGIN

// Function declarations with calling conventions
MYUTILITYLIBRARY_API void __cdecl CDeclFunction();
MYUTILITYLIBRARY_API void __stdcall StdCallFunction();
MYUTILITYLIBRARY_API int __stdcall StdCallFunctionWithParams(int a, int b);
MYUTILITYLIBRARY_API void __fastcall FastCallFunction();
MYUTILITYLIBRARY_API int __fastcall FastCallFunctionWithParams(int a, int b);
MYUTILITYLIBRARY_API HRESULT __stdcall SafeCallFunction();

EXTERN_C_END

#endif // CALLCONVENTION_H


