// Filename: Task3.cpp
// Created by Rickard Bolin on 2019-12-04.
//
// This program removes all leading, trailing and
// multiple spaces in an arbitrary string.
#include <iostream>
using namespace std;

int main() {
    const int DIMLENGTH = 256;
    char input [DIMLENGTH] = {'\0'};
    string answer;
    bool badInput;
    do {
        system("clear");
        cout << "Enter a string: ";
        do {
            badInput = false;
            cin.getline(input, DIMLENGTH, '\n');
            if (cin.fail()) {
                badInput = true;
                cout << "Invalid input, please enter another string: " << endl;
                cin.clear();
            }
        } while (badInput);

        char *ptr;
        ptr = input;

        // The following loops shifts the substring at ptr+1
        // one step to the left if the conditions are met.

        // Handle leading zeros
        while (*ptr == ' ') {
            strcpy(ptr, ptr+1);
        }

        // Make sure there is only one space between words.
        while (*ptr != '\0') {
            if(*ptr == ' ' && *(ptr+1) == ' ') {
                strcpy(ptr, ptr + 1);
            } else {
                ptr++;
            }
        }
        // Check for a potential trailing space
        if(*(ptr-1) == ' '){
            *(ptr-1) = '\0';
        }

        cout << input << endl;

        cout << endl << "Would you like to go again (y/n)?" << endl;
        cin >> answer;
        cin.ignore();
    } while (answer == "y" || answer == "Y");
    system("clear");
    return 0;
}
