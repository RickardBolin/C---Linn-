// Filename: Task6.cpp
// Created by Rickard Bolin on 2019-11-05.
//
// This program calculates and prints the increase or decrease in
// decibel after asking the user to input a reference power and new power.

#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string answer;
    double refPow, pow;
    do{
        cout << endl << "POWER CALCULATIONS" << endl << "=================" << endl
             << "Load reference power: ";
        cin >> refPow;
        cout << "Load power: ";
        cin >> pow;
        // Check for faulty input or other error
        if(cin.fail()){
            cout << endl << endl << "Unfortunately, the program has crashed." << endl <<
                 "You might have entered the wrong data type somewhere. " << endl << endl <<
                 "Please restart the program." << endl << endl;
            exit(0);
        }
        double dB = 10*log10(pow/refPow);
        int units = dB/3;
        cout << "=============================" << endl;
        cout << setprecision(1) << fixed
             << "A change from " << refPow << " to " << pow << " corresponds to " << dB << " dB"<< endl
             << "That is, " << units << " range of 3dB" << endl << endl
             << "One more time? (Y/N): ";

        cin >> answer;
    } while (answer == "y" || answer == "Y");
    return 0;
}
