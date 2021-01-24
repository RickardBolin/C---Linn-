// Filename: Task5.cpp
// Created by Rickard Bolin on 2019-11-05.
//
// This program calculates and prints the remaining time after
// asking the user to input average speed and remaining distance.

#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string answer;
    double avgSpeed, distance;
    do{
        cout << "Enter the average speed (in km/h): ";
        cin >> avgSpeed;
        cout << "Enter the remaining distance in swedish miles (1 swedish mile = 10km): ";
        cin >> distance;
        // Convert to Swedish miles
        distance *= 10000;
        // Check for faulty input or other error
        if (cin.fail()){
            cout << endl << endl << "Unfortunately, the program has crashed." << endl <<
                    "You might have entered the wrong data type somewhere. " << endl << endl <<
                    "Please restart the program." << endl << endl;
            exit(0);
        }

        int time = round(distance/(avgSpeed*(1000.0/3600.0)));
        int hours = time/3600;
        int minutes = round((time%3600)/60.0);

        cout << "The remaining time is:" << endl << setw(2) << setfill('0') <<
                hours << ":" << setw(2) << setfill('0') << minutes << endl;

        cout << "Do you want to do another calculation? (y/n): ";
        cin >> answer;
    } while (answer != "n");
    return 0;
}
