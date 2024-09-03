#pragma once
#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define CALCULATOR_API __declspec(dllimport)
#endif

extern "C" {
    MATHLIBRARY_API int add(int a, int b);
    MATHLIBRARY_API int subtract(int a, int b);
    MATHLIBRARY_API int multiply(int a, int b);
    MATHLIBRARY_API int divide(int a, int b);
}
