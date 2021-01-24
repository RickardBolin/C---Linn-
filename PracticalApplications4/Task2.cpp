// Filename: Task2.cpp
// Created by Rickard Bolin on 2019-12-11.
//
// This program converts fahrenheit to celsius
#include <iostream>
#include <iomanip>

using namespace std;

bool fahrenheitToCelsius(double fahrenheit, double &celsius);

double getFahrenheit();

int main() {
    double celsius;
    char answer;

    do {
        system("clear");
        cout << "Temperature Conversion" << endl;
        cout << "========================" << endl << endl;

        double fahrenheit = getFahrenheit();
        bool positive = fahrenheitToCelsius(fahrenheit, celsius);
        cout << setprecision(3) << celsius << " in Celsius" << endl;
        cout << "Boolean value returned by the conversion function is: ";
        if (positive) {
            cout << "True" << endl << endl;
        } else {
            cout << "False" << endl << endl;

        }
        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');
    system("clear");
    return 0;
}

/**
This function converts a temperature in fahrenheit to celsius
@param fahrenheit - arbitrary double
@param celsius - reference to arbitrary double
@return true if the temperature in celsius is > 0, otherwise false
*/
bool fahrenheitToCelsius(double fahrenheit, double &celsius) {
    celsius = (fahrenheit - 32) * (5.0 / 9);
    return celsius > 0;
}

/**
This function asks the user to enter a temperature in fahrenheit
@return a temperature in fahrenheit
*/
double getFahrenheit() {
    cout << "Enter temperature in fahrenheit: ";
    bool badInput;
    double fahrenheit;
    do {
        badInput = false;
        cin >> fahrenheit;
        if (cin.fail()) {
            badInput = true;
            cout << endl << "Invalid input, please enter another temperature: " << endl;
            cin.clear();
            cin.ignore();
        }
    } while (badInput);
    return fahrenheit;
}