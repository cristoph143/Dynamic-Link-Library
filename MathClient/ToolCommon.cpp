#include "ToolCommon.h"
#include <iostream>

#pragma comment(lib, "wintrust.lib")  // This will link Wintrust.lib automatically

HMODULE loadDLL(const std::wstring& dllPath) {
    HMODULE hLib = LoadLibrary(dllPath.c_str());
    if (hLib == NULL) {
        std::wcerr << L"Failed to load " << dllPath << std::endl;
    }
    return hLib;
}

//HMODULE loadDLL(const std::wstring& dllPath) {
//    // Set Safe DLL Search Mode to prevent DLL hijacking
//    SetDllDirectory(L"");  // Remove the current directory from the search path
//
//    // Load the DLL with restricted search paths to trusted directories (e.g., System32)
//    HMODULE hLib = LoadLibraryEx(dllPath.c_str(), NULL, LOAD_LIBRARY_SEARCH_SYSTEM32 | LOAD_LIBRARY_SEARCH_USER_DIRS);
//
//    if (hLib == NULL) {
//        std::wcerr << L"Failed to load " << dllPath << std::endl;
//        return NULL;
//    }
//
//    // Optionally, verify the DLL's digital signature to ensure it's trusted
//    WINTRUST_FILE_INFO fileInfo = { 0 };
//    fileInfo.cbStruct = sizeof(WINTRUST_FILE_INFO);
//    fileInfo.pcwszFilePath = dllPath.c_str();
//
//    WINTRUST_DATA trustData = { 0 };
//    trustData.cbStruct = sizeof(WINTRUST_DATA);
//    trustData.dwUIChoice = WTD_UI_NONE;  // No UI will be shown
//    trustData.fdwRevocationChecks = WTD_REVOKE_NONE;
//    trustData.dwUnionChoice = WTD_CHOICE_FILE;
//    trustData.pFile = &fileInfo;
//    trustData.dwStateAction = WTD_STATEACTION_VERIFY;
//    trustData.dwProvFlags = WTD_SAFER_FLAG;
//
//    GUID actionGUID = WINTRUST_ACTION_GENERIC_VERIFY_V2;
//
//    LONG result = WinVerifyTrust(NULL, &actionGUID, &trustData);
//    if (result != ERROR_SUCCESS) {
//        PRINT_ERROR_MESSAGE("Failed to verify the digital signature of %ls", dllPath.c_str());
//        //std::wcerr << L"Failed to verify the digital signature of " << dllPath << std::endl;
//        FreeLibrary(hLib);  // Unload the DLL if signature verification fails
//        return NULL;
//    }
//
//    // Signature is valid, continue with loading the DLL
//    PRINT_MESSAGE("Successfully loaded and verified %ls", dllPath.c_str());
//    //std::wcout << L"Successfully loaded and verified " << dllPath << std::endl;
//    return hLib;
//}


// Function to display menu and handle user choices
void runMenu(const std::map<int, MenuOption>& menuOptions, int exitOption) {
    int choice = 0;
    do {
        // Display menu
        PRINT_MESSAGE("\nSelect an option:");
        for (const auto& option : menuOptions) {
            PRINT_MESSAGE("%d. %s", option.first, option.second.description.c_str());
        }
        PRINT_MESSAGE("Enter your choice: ");
        scanf_s("%d", &choice);  // Use scanf for input

        // Execute corresponding action if valid
        if (menuOptions.count(choice)) {
            menuOptions.at(choice).action();
        }
        else {
            PRINT_MESSAGE("Invalid choice. Please try again.");
        }

    } while (choice != exitOption); // Use dynamic exit option
}

// Exit application
void exitApp() {
    PRINT_MESSAGE("Exiting application...");
    exit(0);
}


// Helper function to get a string input from the user
string getStringInput(const std::string& prompt) {
    string input;
    PRINT_MESSAGE("%s", prompt.c_str());
    getline(std::cin.ignore(), input);
    return input;
}
