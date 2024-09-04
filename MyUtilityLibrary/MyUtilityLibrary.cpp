// MyUtilityLibrary.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "MyUtilityLibrary.h"
#include <iostream>


// This is an example of an exported variable
MYUTILITYLIBRARY_API int nMyUtilityLibrary=0;

// This is an example of an exported function.
MYUTILITYLIBRARY_API int fnMyUtilityLibrary(void)
{
    return 0;
}

class CMyUtilityLibrary {
public:
    void ReverseString(char* str);
    void ToUpperCase(char* str);
    void ReadFromFile(const char* filePath);
    void WriteToFile(const char* filePath, const char* content);
};

// Function to reverse a string
void CMyUtilityLibrary::ReverseString(char* str)
{
    if (str == nullptr) return; // Safety check for null input
    size_t len = strlen(str); // Calculate string length
    for (size_t i = 0; i < len / 2; ++i)
    {
        swap(str[i], str[len - i - 1]); // Swap characters to reverse
    }
}

// Function to convert a string to uppercase
void CMyUtilityLibrary::ToUpperCase(char* str)
{
    if (str == nullptr) return; // Safety check for null input
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        str[i] = toupper(static_cast<unsigned char>(str[i])); // Convert to uppercase
    }
}

// Function to read from a file
void CMyUtilityLibrary::ReadFromFile(const char* filePath)
{
    if (filePath == nullptr) return; // Safety check for null file path

    ifstream inFile(filePath); // Open file for reading
    if (!inFile)
    {
        // Handle error, file not opened
        PRINT_ERROR_MESSAGE("Failed to open the file: %s", filePath);
        return;
    }

    string line;
    while (getline(inFile, line)) // Read file line by line
    {
        PRINT_MESSAGE("%s", line.c_str()); // Print or process the content
    }

    inFile.close(); // Close the file after reading
}

// Function to write to a file
void CMyUtilityLibrary::WriteToFile(const char* filePath, const char* content)
{
    if (filePath == nullptr || content == nullptr) return; // Safety check for null inputs

    ofstream outFile(filePath); // Open file for writing
    if (!outFile)
    {
        // Handle error, file not opened
        PRINT_ERROR_MESSAGE("Failed to open the file: %s", filePath);
        return;
    }

    outFile << content; // Write content to the file
    outFile.close(); // Close the file after writing

    PRINT_MESSAGE("File written to: %s", filePath); // Print file location
}


// Global C-style function implementations for compatibility
extern "C" {

    // C-style function to reverse a string
    MYUTILITYLIBRARY_API void ReverseString(char* str)
    {
        CMyUtilityLibrary util;
        util.ReverseString(str); // Call class method
    }

    // C-style function to convert a string to uppercase
    MYUTILITYLIBRARY_API void ToUpperCase(char* str)
    {
        CMyUtilityLibrary util;
        util.ToUpperCase(str); // Call class method
    }

    // C-style function to read from a file
    MYUTILITYLIBRARY_API void ReadFromFile(const char* filePath)
    {
        CMyUtilityLibrary util;
        util.ReadFromFile(filePath); // Call class method
    }

    // C-style function to write to a file
    MYUTILITYLIBRARY_API void WriteToFile(const char* filePath, const char* content)
    {
        CMyUtilityLibrary util;
        util.WriteToFile(filePath, content); // Call class method
    }
}