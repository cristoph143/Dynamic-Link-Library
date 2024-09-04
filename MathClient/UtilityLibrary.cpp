#include "UtilityLibrary.h"

// Define global function pointers
FnReverseString reverseStringFunction = nullptr;
FnToUpperCase toUpperCaseFunction = nullptr;
FnReadFromFile readFromFileFunction = nullptr;
FnWriteToFile writeToFileFunction = nullptr;


// Function to display the menu and handle user input
void displayMenu(HMODULE& hLib, FnReverseString& reverseString, FnToUpperCase& toUpperCase, FnReadFromFile& readFromFile, FnWriteToFile& writeToFile) {
    // Update global function pointers
    reverseStringFunction = reverseString;
    toUpperCaseFunction = toUpperCase;
    readFromFileFunction = readFromFile;
    writeToFileFunction = writeToFile;

    // Define the submenu options
    map<int, MenuOption> submenuOptions = {
        {1, {"Reverse a String", []() {
            std::string str = getStringInput("Enter a string: ");
            reverseStringFunction(&str[0]);
            PRINT_MESSAGE("Reversed String: %s", str.c_str());
        }}},
        {2, {"Convert String to Uppercase", []() {
            string str = getStringInput("Enter a string: ");
            toUpperCaseFunction(&str[0]);
            PRINT_MESSAGE("Uppercase String: %s", str.c_str());
        }}},
        {3, {"Write to File", []() {
            string content = getStringInput("Enter the content to write to the file: ");
            const char* filePath = "output.txt";
            writeToFileFunction(filePath, content.c_str());
            PRINT_MESSAGE("File written to: %s", filePath);
        }}},
        {4, {"Read from File", []() {
            const char* filePath = "output.txt";
            PRINT_MESSAGE("Reading from file: %s", filePath);
            readFromFileFunction(filePath);
        }}},
        {5, {"Exit", []() { PRINT_MESSAGE("Exiting submenu."); }} } // Exit from submenu
    };

    // Call runMenu for the submenu
    runMenu(submenuOptions, 5); // Use dynamic exit option
}

// Function to initialize DLL
bool initializeDLL(HMODULE& hLib, FnReverseString& reverseString, FnToUpperCase& toUpperCase, FnReadFromFile& readFromFile, FnWriteToFile& writeToFile) {
    hLib = LoadLibrary(TEXT("MyUtilityLibrary.dll"));
    if (hLib == NULL) {
        PRINT_ERROR_MESSAGE("Failed to load MyUtilityLibrary.dll");
        return false;
    }

    reverseString = loadFunction<FnReverseString>(hLib, "ReverseString");
    toUpperCase = loadFunction<FnToUpperCase>(hLib, "ToUpperCase");
    readFromFile = loadFunction<FnReadFromFile>(hLib, "ReadFromFile");
    writeToFile = loadFunction<FnWriteToFile>(hLib, "WriteToFile");

    if (!reverseString || !toUpperCase || !readFromFile || !writeToFile) {
        PRINT_ERROR_MESSAGE("Failed to load some functions from MyUtilityLibrary.dll");
        FreeLibrary(hLib);
        return false;
    }

    return true;
}

// Function to execute DLL functions
void executeDLLFunctions(FnReverseString reverseString, FnToUpperCase toUpperCase, FnReadFromFile readFromFile, FnWriteToFile writeToFile) {
    char str[] = "Hello World!";

    reverseString(str);
    PRINT_MESSAGE("Reversed String: %s", str);

    toUpperCase(str);
    PRINT_MESSAGE("Uppercase String: %s", str);

    const char* filePath = "output.txt";
    writeToFile(filePath, "Writing this to a file!");
    PRINT_MESSAGE("File written to: %s", filePath);
    readFromFile(filePath);
}

// Function to unload DLL
void unloadDLL(HMODULE hLib) {
    // Check if the handle is invalid
    if (hLib == NULL) {
        PRINT_MESSAGE("Invalid library handle.");
        return;
    }

    // Attempt to free the library
    if (FreeLibrary(hLib)) {
        PRINT_MESSAGE("DLL successfully unloaded.");
    }
    else {
        PRINT_MESSAGE("Failed to unload DLL.");
    }
}


// Main function to run the utility library application
void runUtilityLibraryApp() {
    HMODULE hLib = NULL;
    FnReverseString reverseString = nullptr;
    FnToUpperCase toUpperCase = nullptr;
    FnReadFromFile readFromFile = nullptr;
    FnWriteToFile writeToFile = nullptr;

    if (initializeDLL(hLib, reverseString, toUpperCase, readFromFile, writeToFile)) {
        executeDLLFunctions(reverseString, toUpperCase, readFromFile, writeToFile);
        // Call displayMenu with the submenu options
        displayMenu(hLib, reverseString, toUpperCase, readFromFile, writeToFile);
        unloadDLL(hLib);
    }
}
// Function to load and retrieve functions from the DLL