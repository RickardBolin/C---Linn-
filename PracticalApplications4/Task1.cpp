// Filename: Task1.cpp
// Created by Rickard Bolin on 2019-12-11.
//
// This program calculates the volume of a cube
#include <iostream>

using namespace std;

void getSide(double &side);

double cubeVolume(double side);

void printVolume(double side);

int main() {
    double side = 0.0;
    char answer;

    do {
        system("clear");
        cout << "Cubes" << endl;
        cout << "=====" << endl << endl;
        getSide(side);
        printVolume(side);

        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');
    system("clear");
    return 0;
}

/**
This function asks the user to enter the length of the side of a cube
@param side - reference to a double
*/
void getSide(double &side) {
    cout << "Enter the side length of a cube to be computed: ";
    bool badInput;
    do {
        badInput = false;
        cin >> side;
        if (cin.fail()) {
            badInput = true;
            cout << endl << "Invalid input, please enter another value: " << endl;
            cin.clear();
            cin.ignore();
        }
    } while (badInput);
}

/**
This function calculates the volume of a cube
@param side - arbitrary positive double
@return the volume of a cube with side-length "side"
*/
double cubeVolume(double side) {
    return side * side * side;
}

/**
This function prints the volume of a cube
@param side - arbitrary positive double
*/
void printVolume(double side) {
    double volume = cubeVolume(side);
    cout << "The volume of the cube is: " << volume << " volume units" << endl;
}
