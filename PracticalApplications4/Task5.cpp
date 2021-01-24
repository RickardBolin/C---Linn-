// Filename: Task5.cpp
// Created by Rickard Bolin on 2019-12-11.
//
// This program estimates the length of a child and prints the result
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct Person {
    int feet;
    int inches;
    double heightInFeet;
};

Person getChild(Person father, Person mother, char gender);

Person getHeight();

char getGender();

int main() {
    char answer;
    do {
        system("clear");
        Person father, mother, child;
        char gender;

        cout << "Enter the height of the father: " << endl;
        father = getHeight();
        cout << "Enter the height of the mother: " << endl;
        mother = getHeight();
        // Get the gender of the child
        gender = getGender();

        child = getChild(father, mother, gender);
        cout << "The estimated height of the child is " << child.feet << " feet and "
             << child.inches << " inches." << endl;

        cout << "One more time (y/n)? ";
        cin >> answer;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (answer == 'y');
    return 0;
}

/**
Ask the user to input a height in feet and inches.
@return structure containing information of a persons height
*/
Person getHeight() {
    bool badInput;
    int dotCounter;
    char *feetString = (char *) calloc(10, sizeof(char));
    char *inchString = (char *) calloc(10, sizeof(char));
    cout << "Enter feet and inches separated by a dot: ";
    do {
        badInput = false;
        dotCounter = 0;
        cin.getline(feetString, 10, '.');
        cin.getline(inchString, 10, '\n');

        // Check if the feet-input is in an acceptable format
        for (int i = 0; i < strlen(feetString); i++) {
            if (!isdigit(feetString[i]) && feetString[i] != '.') {
                badInput = true;
                break;
            }
            if (feetString[i] == '.') {
                dotCounter++;
                if (dotCounter == 2) {
                    badInput = true;
                    break;
                }
            }
        }
        //Reset dot counter and check the inch-input
        dotCounter = 0;
        for (int i = 0; i < strlen(inchString); i++) {
            if (!isdigit(inchString[i]) && inchString[i] != '.') {
                badInput = true;
                break;
            }
            if (feetString[i] == '.') {
                dotCounter++;
                if (dotCounter == 2) {
                    badInput = true;
                    break;
                }
            }
        }
        if (badInput) {
            cout << "Invalid input, try again!" << endl;
        }
    } while (badInput);
    Person p;
    p.feet = strtol(feetString, NULL, 10);
    p.inches = strtol(inchString, NULL, 10);
    p.heightInFeet = p.feet + (1.0 / 12) * p.inches;
    return p;
}

/**
This function estimates the height of a child given the parents and its gender.
@param father - structure containing height information of the father
@param mother - structure containing height information of the mother
@param gender - character describing the gender of the child
@return structure containing height information of the child
*/
Person getChild(Person father, Person mother, char gender) {
    Person child;
    if (gender == 'M') {
        child.heightInFeet = (mother.heightInFeet * (13.0 / 12) + father.heightInFeet) / 2.0;
    } else {
        child.heightInFeet = (mother.heightInFeet + (12.0 / 13) * father.heightInFeet) / 2.0;
    }
    // Separate the feet and inches
    child.feet = child.heightInFeet;
    child.inches = round((child.heightInFeet - child.feet) / (1.0 / 12));
    return child;
}

/**
Ask the user to enter a gender.
@return character 'M' or 'F'
*/
char getGender() {
    cout << "Is the child male or female (M/F)?" << endl;
    bool badInput;
    char gender;
    do {
        badInput = false;
        cin >> gender;
        if (cin.fail() || (gender != 'M' && gender != 'F')) {
            badInput = true;
            cout << endl << "Invalid input, please try again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (badInput);
    return gender;
}
