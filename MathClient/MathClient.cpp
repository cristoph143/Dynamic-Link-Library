// MathClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MathClient.h"
#include "ToolCommon.h"
#include "UtilityLibrary.h"

int main() {
    // Define the menu options with their descriptions and associated actions
    map<int, MenuOption> menuOptions = {
        {1, {"Static Library (Square, Cube, Factorial)", runStaticLibraryApp}},
        {2, {"Dynamic Library 1 (Fibonacci Sequence)", runDynamicLibraryApp1}},
        {3, {"Dynamic Library 2 (Basic Calculator)", runDynamicLibraryApp2}},
        {4, {"Utility Library (File I/O, String Operations)", runUtilityLibraryApp}},
        {5, {"Exit", exitApp}}
    };

    // Run the dynamic menu
    // Pass the exit option number to runMenu
    runMenu(menuOptions, 5); // 5 is the exit option number

    return 0;
}

void runStaticLibraryApp() {
    int num = 5;

    // Use the macro to print the initial message
    PRINT_MESSAGE("Running Static Library (Square, Cube, Factorial)");

    // Use the macro for dynamic content
    PRINT_MESSAGE("Square of %d is: %d", num, square(num));
    PRINT_MESSAGE("Cube of %d is: %d", num, cube(num));
    PRINT_MESSAGE("Factorial of %d is: %d", num, factorial(num));
}


void runDynamicLibraryApp1() {
    PRINT_MESSAGE("Running Dynamic Library 1 (Fibonacci Sequence)");

    fibonacci_init(1, 1);
    do {
        PRINT_MESSAGE("%d: %llu", fibonacci_index(), fibonacci_current());
    } while (fibonacci_next());

    PRINT_MESSAGE("%d Fibonacci sequence values fit in an unsigned 64-bit integer.", fibonacci_index() + 1);
}

void runDynamicLibraryApp2() {
    PRINT_MESSAGE("Running Dynamic Library 2 (Basic Calculator)");

    int a = 10, b = 5;

    PRINT_MESSAGE("Add: %d", add(a, b));
    PRINT_MESSAGE("Subtract: %d", subtract(a, b));
    PRINT_MESSAGE("Multiply: %d", multiply(a, b));
    PRINT_MESSAGE("Divide: %d", divide(a, b));
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
