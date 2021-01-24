// Filename: Task4.cpp
// Created by Rickard Bolin on 2019-12-11.
//
// This program encrypts a user-entered text.
#include <iostream>
using namespace std;

char* encrypt(const char* pText);

int main() {
    char answer;
    do {
        const int STRING_LENGTH = 100;
        char* pText = (char*)calloc(STRING_LENGTH, sizeof(char));
        bool badInput;
        cout << "Enter text to encrypt:" << endl;
        do {
            badInput = false;
            // Check for faulty input or other error while asking user for input
            cin.getline(pText, STRING_LENGTH, '\n');
            if (cin.fail()) {
                badInput = true;
                cout << "Invalid input, please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (badInput);

        // Encrypt the text
        char *pEncryptedText = encrypt(pText);

        // If the input is correct, print it and ask if the user wants to go again.
        // If the input is not correct, ie contains numbers, ask for new input.
        if (pEncryptedText != NULL) {
            cout << pEncryptedText << endl;
            cout << "One more time (y/n)? ";
            cin >> answer;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            answer = 'y';
        }
        free(pText);
        free(pEncryptedText);
    } while(answer == 'y');
    return 0;
}

/**
This function
@param pEncryptedText - structure containing height information of the father
@param gender - character describing the gender of the child
@return structure containing height information of the child
*/
char* encrypt(const char* pText) {
    char* pEncryptedText = (char*)calloc(strlen(pText), sizeof(char));
    const char* textPtr = pText;
    char* encryptedPtr = pEncryptedText;
    for(int i = 0; i < strlen(pText); i++){
        // If white space, don't change it.
        if (*textPtr == ' ') {
            *encryptedPtr = *textPtr;
        } else if ((64 < *textPtr && *textPtr < 91)) {
            // If the character is an upper case letter:
            if (*textPtr < 88) {
                *encryptedPtr = *textPtr + 3;
            } else {
                // X, Y, Z -> A, B, C
                *encryptedPtr = *textPtr + 3 - (26);
            }
        } else if (96 < *textPtr && *textPtr < 123) {
            // If the character is a lower case letter:
            if (*textPtr < 119) {
                *encryptedPtr = *textPtr + 3;
            } else {
                // x, y, z -> a, b, c
                *encryptedPtr = *textPtr + 3 - (26);
            }
        } else {
            cout << "Input contains non-letter characters, please try again." << endl;
            return NULL;
        }
        textPtr++;
        encryptedPtr++;
    }
    return pEncryptedText;
}
