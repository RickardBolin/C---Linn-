// Filename: Task7.cpp
// Created by Rickard Bolin on 2019-11-05.
//
// This program calculates and prints the sum of a three digit number
// that the user is requested to input.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string answer;
    int number, first, second, third, sum, digits;

    do{
        cout << "Enter a three-digit number: ";
        do{
            cin >> number;
            // Check for faulty input or other error
            if (cin.fail()){
                cout << endl << endl << "Unfortunately, the program has crashed." << endl <<
                     "You might have entered the wrong data type or a too large number. " << endl << endl <<
                     "Please restart the program." << endl << endl;
                exit(0);
            }
            // Check if the number of digits in the entered number is three
            digits = 0;
            int n = number;
            while (n != 0) {
                n = n / 10;
                digits++;
            }
            if (digits != 3){
                cout << "Wrong number of digits, please enter a three-digit number:" << endl;
            }
        } while (digits != 3);

        first = number/100;
        second = (number - first*100)/10;
        third = number%10;
        sum = first + second + third;

        cout << "The sum of the digits is: " << sum << endl << endl
             << "Do you want to do another calculation? (y/n): ";
        cin >> answer;
    } while (answer != "n");
    return 0;
}
