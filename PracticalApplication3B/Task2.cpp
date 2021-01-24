// Filename: Task2.cpp
// Created by Rickard Bolin on 2019-12-03.
//
// This program takes an arbitrary name as input and removes
// all letters in the first name except the first one.
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    const int DIMLENGTH = 256;
    char input[DIMLENGTH] = {'\0'};
    string answer;
    bool badInput;
    do {
        system("clear");
        cout << "Enter a name: ";
        do {
            badInput = false;
            cin.getline(input, DIMLENGTH, '\n');
            if (cin.fail()) {
                badInput = true;
                cout << "Invalid input, please enter another string: " << endl;
                cin.clear();
            }
        } while (badInput);

        int spaceIndex = 0;
        // Find first whitespace
        while (input[spaceIndex] != ' ' && input[spaceIndex] != '\0') {
            spaceIndex++;
        }
        // Move the string to cover the first name except the first Letter
        memmove(input + 1, input + spaceIndex, strlen(input) - spaceIndex);
        // End the string on the index after the new last character
        input[strlen(input) + 1 - spaceIndex] = '\0';
        cout << input << endl;

        cout << endl << "Would you like to go again (y/n)?" << endl;
        cin >> answer;
        cin.ignore();
    } while (answer == "y" || answer == "Y");
    system("clear");
    return 0;
}
