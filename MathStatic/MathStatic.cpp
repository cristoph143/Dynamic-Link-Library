// MathStatic.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "MathStatic.h"

int square(int x) {
    return x * x;
}

int cube(int x) {
    return x * x * x;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

