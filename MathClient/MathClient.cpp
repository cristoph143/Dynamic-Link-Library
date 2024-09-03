// MathClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MathClient.h"

int main() {
    // Define the menu options with their descriptions and associated actions
    map<int, MenuOption> menuOptions = {
        {1, {"Static Library (Square, Cube, Factorial)", runStaticLibraryApp}},
        {2, {"Dynamic Library 1 (Fibonacci Sequence)", runDynamicLibraryApp1}},
        {3, {"Dynamic Library 2 (Basic Calculator)", runDynamicLibraryApp2}},
        {4, {"Exit", exitApp}}
    };

    // Run the dynamic menu
    runMenu(menuOptions);

    return 0;
}

void runMenu(const map<int, MenuOption>& menuOptions) {
    int choice = 0;
    do {
        // Display menu
        cout << "\nSelect an option:\n";
        for (const auto& option : menuOptions) {
            cout << option.first << ". " << option.second.description << endl;
        }
        cout << "Enter your choice: ";
        cin >> choice;

        // Execute corresponding action if valid
        if (menuOptions.count(choice)) {
            menuOptions.at(choice).action();
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4); // Option 4 for "Exit"
}

// Function implementations
void runStaticLibraryApp() {
    int num = 5;
    cout << "Running Static Library (Square, Cube, Factorial)" << endl;
    cout << "Square of " << num << " is: " << square(num) << endl;
    cout << "Cube of " << num << " is: " << cube(num) << endl;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
}

void runDynamicLibraryApp1() {
    cout << "Running Dynamic Library 1 (Fibonacci Sequence)" << endl;
    fibonacci_init(1, 1);
    do {
        cout << fibonacci_index() << ": " << fibonacci_current() << endl;
    } while (fibonacci_next());
    cout << fibonacci_index() + 1 << " Fibonacci sequence values fit in an unsigned 64-bit integer." << endl;
}

void runDynamicLibraryApp2() {
    cout << "Running Dynamic Library 2 (Basic Calculator)" << endl;
    int a = 10, b = 5;
    cout << "Add: " << add(a, b) << endl;
    cout << "Subtract: " << subtract(a, b) << endl;
    cout << "Multiply: " << multiply(a, b) << endl;
    cout << "Divide: " << divide(a, b) << endl;
}

void exitApp() {
    cout << "Exiting..." << endl;
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
