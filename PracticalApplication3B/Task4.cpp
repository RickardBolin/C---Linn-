// Filename: Task4.cpp
// Created by Rickard Bolin on 2019-12-04.
//
// Creates abbreviation of arbitrary term.
// Terms containing only vowels cannot be abbreviated.


//
// P.S! I'm not certain that I have interpreted the instructions
// 100% correctly... I could not figure out in what order you wanted
// me to do things. Should I:
//                  remove duplicates first and then check length or
//                  check length and then possibly remove duplicates.
//
// I decided to to with option 2, which means that:
// BBBBB -> BBBBB  and  BBBBBB -> B
//
// Hopefully, I choose the correct option. I just wanted you to know
// that I've thought about it!
//

#include <iostream>
using namespace std;

bool isConsonant(char c);

int main() {
    string answer;
    const int DIMLENGTH = 256;
    char input [DIMLENGTH] = {'\0'};
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
        cout << input << " -> ";
        // Remove all vowels
        while (*ptr != '\0') {
            if(!isConsonant(*ptr)) {
                strcpy(ptr, ptr + 1);
            } else {
                ptr++;
            }
        }
        // If the string is shorter than 5 characters, print them.
        // Otherwise, remove all duplicate characters
        if (strlen(input) > 5){
            ptr = input;
            while (*ptr != '\0') {
                if(*ptr == *(ptr+1)) {
                    strcpy(ptr, ptr + 1);
                } else {
                    ptr++;
                }
            }
        }
        // If the string is longer than 5 characters, only keep the three first and last two.
        if (strlen(input) > 5) {
            ptr = input;
            strcpy(ptr + 3, ptr + strlen(input) - 2);
        }
        cout << input << endl;

        cout << endl << "Would you like to go again (y/n)?" << endl;
        cin >> answer;
        cin.ignore();
    } while (answer == "y" || answer == "Y");
    system("clear");
    return 0;
    }

/**
* Checks if the character c is a consonant.
*
* @param c - Arbitrary character.
*/
bool isConsonant(char c){
    const string CONSONANTS = "bcdfghjklmnpqrstvwxz";
    return CONSONANTS.find(tolower(c)) != string::npos;
}