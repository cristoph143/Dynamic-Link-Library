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

void demonstrateCallingConventions() {
    HMODULE hLib = loadDLL(L"MyUtilityLibrary.dll");

    // Retrieve function pointers
   // Load function pointers
    auto cDeclFunc = loadFunction<CDeclFunc>(hLib, "CDeclFunction");
    auto stdCallFunc = loadFunction<StdCallFunc>(hLib, "StdCallFunction");
    auto stdCallFuncWithParams = loadFunction<StdCallFuncWithParams>(hLib, "StdCallFunctionWithParams");
    auto fastCallFunc = loadFunction<FastCallFunc>(hLib, "FastCallFunction");
    auto fastCallFuncWithParams = loadFunction<FastCallFuncWithParams>(hLib, "FastCallFunctionWithParams");
    auto safeCallFunc = loadFunction<SafeCallFunc>(hLib, "SafeCallFunction");

    if (!cDeclFunc || !stdCallFunc || !stdCallFuncWithParams || !fastCallFunc || !fastCallFuncWithParams || !safeCallFunc) {

        PRINT_ERROR_MESSAGE("Failed to retrieve one or more function pointers from MyUtilityLibrary.dll");
        FreeLibrary(hLib);
        return;
    }

    PRINT_MESSAGE("Demonstrating Calling Conventions");

    PRINT_MESSAGE("Cdecl Function: Calling function with __cdecl calling convention.");
    cDeclFunc();

    PRINT_MESSAGE("Stdcall Function: Calling function with __stdcall calling convention.");
    stdCallFunc();

    PRINT_MESSAGE("Stdcall Function With Params: Calling function with __stdcall calling convention and parameters.");
    int result = stdCallFuncWithParams(10, 5);
    PRINT_MESSAGE("StdCallFunctionWithParams returned: %d", result);

    PRINT_MESSAGE("Fastcall Function: Calling function with __fastcall calling convention.");
    fastCallFunc();

    PRINT_MESSAGE("Fastcall Function With Params: Calling function with __fastcall calling convention and parameters.");
    result = fastCallFuncWithParams(10, 5);
    PRINT_MESSAGE("FastCallFunctionWithParams returned: %d", result);

    PRINT_MESSAGE("Safecall Function: Calling function with __stdcall calling convention and HRESULT return type.");
    HRESULT hr = safeCallFunc();
    if (FAILED(hr)) {
        PRINT_ERROR_MESSAGE("SafeCallFunction failed with HRESULT: 0x%08X", hr);
    }

    FreeLibrary(hLib);
}


// Function to initialize DLL
bool initializeDLL(HMODULE& hLib, FnReverseString& reverseString, FnToUpperCase& toUpperCase, FnReadFromFile& readFromFile, FnWriteToFile& writeToFile) {
    hLib = loadDLL(L"MyUtilityLibrary.dll");

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