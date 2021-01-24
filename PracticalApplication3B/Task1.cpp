// Filename: Task1.cpp
// Created by Rickard Bolin on 2019-12-04.
//
// Print a user-entered string in reverse.

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

        int length;
        char *endPtr;
        length = strlen(input);
        char reversed[length+1];
        endPtr = input + length -1;

        for (int i = 0; i < length; i++) {
            reversed[i] = *endPtr;
            endPtr--;
        }
        reversed[length] = '\0';
        cout << reversed << endl;

        cout << endl << "Would you like to go again (y/n)?" << endl;
        cin >> answer;
        cin.ignore();
    } while (answer == "y" || answer == "Y");
    system("clear");
    return 0;
}


