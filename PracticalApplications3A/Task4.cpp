// Filename: Task4.cpp
// Created by Rickard Bolin on 2019-12-03.
//
// This program takes a social security number as input
// and checks if it belongs to a man or a woman.
#include <iostream>

using namespace std;

bool checkFormat(char *ssn);

int main() {

    string answer;
    const int DIMLENGTH = 100;
    char ssn[DIMLENGTH] = {'\0'};
    bool isGirl;
    do {
        system("clear");
        cout << "Please enter a Social Security Number: " << endl;
        do {
            // Check for faulty input or other error while asking user for input
            cin.getline(ssn, DIMLENGTH, '\n');
            if (cin.fail() || !checkFormat(ssn)) {
                cout << "Invalid number, please enter the number in format: YYMMDD-XXXX: " << endl;
                cin.clear();
            }
        } while (!checkFormat(ssn));

        // If the digit at second to last digit is even, set isGirl to true
        isGirl = (ssn[strlen(ssn) - 2] % 2 == 0);

        cout << "The Social Security Number " << ssn << " belongs to a ";
        if (isGirl) {
            cout << "woman." << endl;
        } else {
            cout << "man." << endl;
        }

        cout << endl << "Want to check another Social Security Number (y/n)?" << endl;
        cin >> answer;
        cin.ignore();
    } while (answer == "y" || answer == "Y");
    system("clear");
    return 0;
}


/**
 * Checks that the input is of the right length, consisting of digits and that, if
 * it is 11 characters long, it has the hyphen at the right index.
 *
 * @param ssn - C-string with 10 or 11 characters.
 */
bool checkFormat(char ssn[]) {
    int hyphenIndex = 6;

    if (strlen(ssn) == 10) {
        for (int i = 0; i < 10; i++) {
            if (!isdigit(ssn[i])) {
                return false;
            }
        }
        return true;
    } else if (strlen(ssn) == 11) {
        for (int i = 0; i < 11; i++) {
            if (!isdigit(ssn[i]) && i != hyphenIndex) {
                return false;
            }
        }
        if (ssn[hyphenIndex] == '-') {
            return true;
        }
    }
    return false;
}
