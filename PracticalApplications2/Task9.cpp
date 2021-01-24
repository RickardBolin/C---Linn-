// Filename: Task9.cpp
// Created by Rickard Bolin on 2019-11-20.
//
// This program calculates and prints the sum of the digits of an integer, entered by the user.

#include <limits.h>
#include <math.h>
#include <iostream>
using namespace std;

int main(){

    string answer;
    long number, remainder;

    do{
        cout << "Enter an integer: ";
        // Check for faulty input or other error while asking user for input
        label:
        cin >> number;
        if(cin.fail() || number > __INT_MAX__ || number < 0){
            cout << "Incorrect input, please enter another integer: " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto label;
        }

        int num = number;
        int sum = 0;
        while (num != 0) {
            remainder = num%10;
            sum += remainder;
            num = num/10;
        }
        cout << "The sum of the digits is: " << sum << endl;
        cout << "Do you want to go again? (y/n): ";
        cin >> answer;
    } while (answer != "n");

    return 0;
}
