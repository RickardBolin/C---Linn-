// Filename: Task6.cpp
// Created by Rickard Bolin on 2019-12-11.
//
// This program asks the user for a sum and then calculates and prints a potential discount.
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// Remember to declare all functions (prototypes)!
void load(double &sum);

double discount(double sum);

void print(double sum, double discountKr);

int main() {
    double sum = 0.0, discountKr = 0.0;
    char answer;
    do {
        system("CLS"); // Clear screen
        cout << "Discount" << endl;
        cout << "======" << endl << endl;
        load(sum);
// To read the input sum from user – complete this function call,
// by writing the necessary function definition!
        discountKr = sum * discount(sum) / 100;
// To calculate the discount – complete the function call ("discount(sum)")
// with a function definition
        sum = sum - discountKr;
        print(sum, discountKr);
        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
    } while (toupper(answer) == 'Y');
    return 0;
}

/**
Ask the user to input a sum
@param sum, reference to a double
*/
void load(double &sum) {
    bool badInput;
    cout << "Enter the sum: ";
    do {
        badInput = false;
        // Check for faulty input or other error while asking user for input
        cin >> sum;
        if (cin.fail() || sum < 0) {
            badInput = true;
            cout << "Invalid input, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (badInput);
}

/**
Check how much discount a certain sum is eligible to
@param sum, arbitrary double.
@return the discount in percent that will be applied
*/
double discount(double sum) {
    if (sum < 500) {
        return 0;
    } else if (500 <= sum && sum < 1000) {
        return 5.0;
    } else if (1000 <= sum && sum < 5000) {
        return 10.0;
    } else {
        return 15.0;
    }
}

/**
Prints the sum and discount
@param sum, the sum.
@param dKr, the amount of discount.
*/
void print(double sum, double dKr) {
    cout << "------------------------------------" << endl << fixed << setfill(' ')
         << "Discount" << setw(7) << ":  " << setw(11) << setfill('.')
         << setprecision(2) << round(dKr) << " kr" << endl << setfill(' ')
         << "Net sum" << setw(8) << ":  " << setw(11) << setfill('.')
         << setprecision(2) << round(sum) << " kr" << endl
         << "------------------------------------" << endl;
}
