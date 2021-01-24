// Filename: Task3.cpp
// Created by Rickard Bolin on 2019-12-03.
//
// This program takes two integers as inputs, calculates the GCD and
// prints the fraction, both in mixed and rational form, in its
// most abbreviated form.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    std::cout << "Laboration 1!" << std::endl;

    string answer;
    signed int fraction [2]; //Index 0 = numerator, index 1 = denominator
    bool badInput;
    do {
        system("clear");
        cout << "FRACTION CALCULATOR" << endl
             << "=========================" << endl << endl
             << "Enter the numerator: ";
        do {
            // Check for faulty input or other error while asking user for input
            badInput = false;
            cin >> fraction[0];
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
            cin >> fraction[1];
            if (cin.fail() || fraction[1] == 0) {
                cout << "Incorrect input, please try again "
                        "(remember that division by zero is undefined):" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                badInput = true;
            }
        } while (badInput);

        if(fraction[1] < 0){
            fraction[0] *= -1;
            fraction[1] *= -1;
        }

        // Euclids algorithm to find the greatest common divisor:
        int gcd = 1;
        if (fraction[0] != 0) {
            signed int x = abs(fraction[0]);
            signed int y = abs(fraction[1]);
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
        fraction[0] /= gcd;
        fraction[1] /= gcd;

        // Handle a few different cases to make the output look nice.
        if(fraction[1] == 1 || fraction[0] == 0){
            cout << "The fraction can be abbreviated to: " << fraction[0] << endl;
        }
        else if (fraction[0] > fraction[1]) {
            cout << "The fraction can be abbreviated to: "
                 << fraction[0] << "/" << fraction[1] << " = "
                 << fraction[0] / fraction[1] << " "
                 << fraction[0] % fraction[1] << "/" << fraction[1] << endl;
        }
        else if (fraction[0] == fraction[1]){
            cout << "The fraction can be abbreviated to: 1" << endl;
        }
        else if (gcd == 1){
            cout << "The fraction can not be abbreviated. The final fraction is: "
                 << fraction[0] << "/" << fraction[1] << endl;
        }
        else{
            cout << "The final fraction is: "
                 << fraction[0] << "/" << fraction[1] << endl;
        }
        cout << "Do you want to go again? (y/n): ";
        cin >> answer;
    } while (answer != "n");
    system("clear");
    return 0;
}
