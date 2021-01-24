// Filename: Task5.cpp
// Created by Rickard Bolin on 2019-12-03.
//
// This program takes a string as input and checks if that string is a palindrome.
#include <iostream>

using namespace std;

bool isPalindrome(char input[]);

int main() {

    const int DIMLENGTH = 256;
    string answer;
    char input[DIMLENGTH] = {'\0'};
    bool badInput;
    do {
        system("clear");
        badInput = false;
        cout << "Enter a string: ";
        do {
            cin.getline(input, DIMLENGTH, '\n');
            if (cin.fail()) {
                badInput = true;
                cout << "Invalid input, please enter another string: " << endl;
                cin.clear();
            }
        } while (badInput);

        if (isPalindrome(input)) {
            cout << "The string is a palindrome!" << endl;
        } else {
            cout << "The string is not a palindrome!" << endl;
        }
        cout << endl << "Would you like to make a new calculation (y/n)?" << endl;
        cin >> answer;
        cin.ignore();
    } while (answer == "y" || answer == "Y");
    system("clear");
    return 0;
}

/**
 * Checks if a C-string is a palindrome. Ignores white spaces and capital letters.
 *
 * @param input - Arbitrary C-string.
 */
bool isPalindrome(char input[]) {
    for (int left = 0, right = strlen(input) - 1; left < right; left++, right--) {

        // Skip the spaces
        while (input[left] == ' ') {
            left++;
        }
        while (input[right] == ' ') {
            right--;
        }

        if (tolower(input[left]) != tolower(input[right])) {
            return false;
        }
    }
    return true;
}
