// Filename: Task10.cpp
// Created by Rickard Bolin on 2019-11-06.
//
// This program calculates compound interest with a given interest rate
// after asking the user to input initial amount and number of years.

#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double INTEREST_RATE = 3.0;

void load_input(double &initialAmount, double &years);
double calculate_capital(double initialAmount, double years);
void print_capital(double capital, double years);

int main()
{
    double initialAmount, years, capital;
    string answer;

    do{
        // Save the current formatting of cout.
        ios init(nullptr);
        init.copyfmt(cout);

        cout << "COMPOUND INTEREST" << endl << "==============" << endl << endl;
        load_input(initialAmount, years);
        capital = calculate_capital(initialAmount, years);
        print_capital(capital, years);

        cout << endl <<  "Do you want to do another calculation? (y/n): ";
        cin >> answer;

        // Load the formatting that we saved before.
        // This will make the program print in the same format every run instead
        // of changing from one format in the first to an other format in the rest.
        cout.copyfmt(init);
    } while (answer == "y" || answer == "Y");
    return 0;
}

/**
 * Loads all necessary input for the "calculate-capital"-function from the user.
 *
 * @param initialAmount - Initial invested amount
 *        years         - Number of years that the interest rate is compounded
 */
void load_input(double &initialAmount, double &years){
    cout << "Load initial amount: ";
    cin >> initialAmount;
    cout << "Load number of years: ";
    cin >> years;
    // Check for faulty input or other error
    if (cin.fail()){
        cout << endl << endl << "Unfortunately, the program has crashed." << endl
             << "Please restart the program." << endl << endl;
        exit(0);
    }
}

/**
 * Calculates the total capital.
 *
 * @param initialAmount - Initial invested amount
 *        years         - Number of years that the interest rate is compounded
 */
double calculate_capital(double initialAmount, double years){
    double capital = initialAmount * pow((1 + INTEREST_RATE/100), years);
    return capital;
}

/**
 * Loads all necessary input for the "calculate-capital"-function from the user.
 *
 * @param capital - Total capital after compounding.
 *        years   - Number of years that the interest rate is compounded
 */
void print_capital(double capital, double years){
    cout << "The capital with " << INTEREST_RATE << "% interest rate and after " << years
         << " years will be: "
         << fixed << setprecision(2) << right << setfill('_') << setw(12)
         << capital << " SEK" << endl;
}
