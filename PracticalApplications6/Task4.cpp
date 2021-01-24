// Filename: Task4.cpp
// Created by Rickard Bolin on 2020-01-06.
//
// This function reads characters from a .dat file, sorts them by case and writes
// them into different .txt-files, upper and lower.
#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;

bool sortByCase(const char *inf, const char *upperFile, const char *lowerFile);

int main() {
    char upper[] = "./files/upper.txt";
    char lower[] = "./files/lower.txt";
    sortByCase("./files/abcfile.dat", upper, lower);

    return 0;
}

/**
This function reads characters from a .dat file, sorts them by case and writes
them into their respective .txt-files, upper and lower.
@param inf - the infile that will be read from
@param upperFile - the .txt-outfile that upper case letters will be written to
@param lowerFile - the .txt-outfile that lower case letters will be written to
@return true if all files opened, otherwise false
*/
bool sortByCase(const char *inf, const char *upperFile, const char *lowerFile) {
    ifstream infile(inf);
    ofstream upper(upperFile);
    ofstream lower(lowerFile);

    if (!infile.is_open() || !upper.is_open() || !lower.is_open()) {
        cout << "Failed to open one of the files!" << endl;
        return false;
    }

    char ch;
    // Continue iterating while we keep reading characters or
    // we reach EOF (infile.get(EOF) returns 0). Without ch > 0,
    // we get a weird character at the end of upper.txt.
    while (infile.get(ch) && ch > 0) {
        // Skip line-breaks
        if (ch != '\n') {
            // If the character is upper-case:
            if (ch == toupper(ch)) {
                // Write to upper file
                upper << ch;
            } else {
                // Write to lower file
                lower << ch;
            }
        }
    }
    infile.close();
    upper.close();
    lower.close();
    return true;
}
