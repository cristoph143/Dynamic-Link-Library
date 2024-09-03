#pragma once
#include <iostream>
#include <functional>
#include <map>
#include "MathLibrary.h"      // For Dynamic1 (Fibonacci)
#include "Calculator.h"       // For Dynamic2 (Basic Calculator)
#include "MathStatic.h"

using namespace std;

// Define a reusable menu structure
struct MenuOption {
    string description;
    function<void()> action;
};


// Function prototypes
void runMenu(const map<int, MenuOption>& menuOptions);
void runStaticLibraryApp();
void runDynamicLibraryApp1();
void runDynamicLibraryApp2();
void exitApp();
