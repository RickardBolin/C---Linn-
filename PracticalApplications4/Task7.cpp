// Filename: Task7.cpp
// Created by Rickard Bolin on 2019-12-11.
//
// This program asks the user to enter two fraction and an operation,
// then prints the result.
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

/**
Fraction structure containing two signed integers, one numerator and one denominator.
*/
struct Rat {
    signed int numerator;
    signed int denominator;
};

Rat getFraction();

void reduce(Rat &fraction);

int displayMenu();

Rat addition(Rat firstFraction, Rat secondFraction);

Rat subtraction(Rat firstFraction, Rat secondFraction);

Rat multiplication(Rat firstFraction, Rat secondFraction);

Rat division(Rat firstFraction, Rat secondFraction);

void printResult(Rat firstFraction, Rat secondFraction, Rat result, int choice);

int main() {

    string answer;
    Rat firstFraction, secondFraction, result;

    do {
        system("clear");
        cout << "FRACTION CALCULATOR" << endl
             << "=========================" << endl << endl;

        cout << "Enter the first fraction:" << endl;
        firstFraction = getFraction();
        cout << endl << "Enter the second fraction:" << endl;
        secondFraction = getFraction();
        bool badInput;
        int choice = displayMenu();
        do {
            badInput = false;
            switch (choice) {
                case 1:
                    result = addition(firstFraction, secondFraction);
                    break;
                case 2:
                    result = subtraction(firstFraction, secondFraction);
                    break;
                case 3:
                    result = multiplication(firstFraction, secondFraction);
                    break;
                case 4:
                    result = division(firstFraction, secondFraction);
                    break;
                default:
                    cout << "Incorrect input, please try again." << endl;
                    badInput = true;
            }
        } while (badInput);
        printResult(firstFraction, secondFraction, result, choice);

        cout << "Do you want to go again? (y/n): ";
        cin >> answer;
    } while (answer != "n");
    system("clear");
    return 0;
}

/**
Get a fraction from the user
@return a structure containing a numerator and denominator
*/
Rat getFraction() {
    Rat fraction;
    bool badInput;
    cout << "Enter the numerator: ";
    do {
        // Check for faulty input or other error while asking user for input
        badInput = false;
        cin >> fraction.numerator;
        if (cin.fail()) {
            cout << "Incorrect input, please try again:" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            badInput = true;
        }
    } while (badInput);
    cout << "Enter the denominator: ";
    do {
        // Check for faulty input or other error while asking user for input
        badInput = false;
        cin >> fraction.denominator;
        if (cin.fail() || fraction.denominator == 0) {
            cout << "Incorrect input, please try again "
                    "(remember that division by zero is undefined):" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            badInput = true;
        }
    } while (badInput);
    if (fraction.denominator < 0) {
        fraction.numerator *= -1;
        fraction.denominator *= -1;
    }
    return fraction;
}

/**
Reduces a fraction to lowest terms using Euclids algorithm
@param fraction, reference to structure containing two signed integers.
*/
void reduce(Rat &fraction) {
    // Euclids algorithm to find the greatest common divisor:
    int gcd = 1;
    if (fraction.numerator != 0) {
        signed int x = abs(fraction.numerator);
        signed int y = abs(fraction.denominator);
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        while (true) {
            int rem = x % y;
            if (rem == 0) {
                gcd = y;
                break;
            }
            x = y;
            y = rem;
        }
    }
    fraction.numerator /= gcd;
    fraction.denominator /= gcd;
}

/**
Display the main menu
@return the choice of the user (integer)
*/
int displayMenu() {
    int choice;
    system("clear");
    cout << endl << "Choose operation:" << endl
         << "1.  Addition" << endl
         << "2.  Subtraction" << endl
         << "3.  Multiplication" << endl
         << "4.  Division" << endl << endl
         << "Select: ";
    cin >> choice;
    return choice;
}

/**
Add two fractions
@param firstFraction, structure containing two signed integers.
@param secondFraction, structure containing two signed integers.
@return the result of the addition
*/
Rat addition(Rat firstFraction, Rat secondFraction) {
    Rat result;
    result.numerator = firstFraction.numerator * secondFraction.denominator +
                       secondFraction.numerator * firstFraction.denominator;
    result.denominator = firstFraction.denominator * secondFraction.denominator;
    reduce(result);
    return result;
}

/**
Subtract one fraction from another
@param firstFraction, structure containing two signed integers.
@param secondFraction, structure containing two signed integers.
@return the result of the subtraction
*/
Rat subtraction(Rat firstFraction, Rat secondFraction) {
    Rat result;
    result.numerator = firstFraction.numerator * secondFraction.denominator -
                       secondFraction.numerator * firstFraction.denominator;
    result.denominator = firstFraction.denominator * secondFraction.denominator;
    reduce(result);
    return result;
}

/**
Multiplication of one fraction by another
@param firstFraction, structure containing two signed integers.
@param secondFraction, structure containing two signed integers.
@return the result of the multiplication
*/
Rat multiplication(Rat firstFraction, Rat secondFraction) {
    Rat result;
    result.numerator = firstFraction.numerator * secondFraction.numerator;
    result.denominator = firstFraction.denominator * secondFraction.denominator;
    reduce(result);
    if (result.denominator < 0) {
        result.numerator *= -1;
        result.denominator *= -1;
    }
    return result;
}

/**
Divide one fraction by another
@param firstFraction, structure containing two signed integers.
@param secondFraction, structure containing two signed integers.
@return the result of the division
*/
Rat division(Rat firstFraction, Rat secondFraction) {
    Rat result;
    result.numerator = firstFraction.numerator * secondFraction.denominator;
    result.denominator = firstFraction.denominator * secondFraction.numerator;
    reduce(result);
    if (result.denominator < 0) {
        result.numerator *= -1;
        result.denominator *= -1;
    }
    return result;
}

/**
A function used to print the result of a fraction calculation in a nice way.
@param firstFraction, structure containing two signed integers.
@param secondFraction, structure containing two signed integers.
*/
void printResult(Rat firstFraction, Rat secondFraction, Rat result, int choice) {
    map<int, char> operation;
    operation[1] = '+';
    operation[2] = '-';
    operation[3] = '*';
    operation[4] = '/';
    cout << "The result is: " << endl
         << "(" << firstFraction.numerator << "/" << firstFraction.denominator << ")"
         << operation[choice]
         << "(" << secondFraction.numerator << "/" << secondFraction.denominator << ") = ";
    // Handle a few different cases to make the output look nice.
    if (result.denominator == 1 || result.numerator == 0) {
        cout << result.numerator;
    } else if (result.numerator == result.denominator) {
        cout << "1";
    } else {
        cout << result.numerator << "/" << result.denominator;
    }
    cout << endl << endl;
}
