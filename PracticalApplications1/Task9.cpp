// Filename: Task9.cpp
// Created by Rickard Bolin on 2019-11-06.
//
// This program calculates the value of a investment after four years
// after asking the user to input the rate of change for those years.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string answer;
    double investment, p1, p2, p3, p4;

    do{
        cout << "Enter invested amount: ";
        cin >> investment;
        cout << "Enter the percentage change (i.e 4.1 or -3.2) for: " << endl;
        cout << "Year 1: ";
        cin >> p1;
        cout << "Year 2: ";
        cin >> p2;
        cout << "Year 3: ";
        cin >> p3;
        cout << "Year 4: ";
        cin >> p4;
        // Check for faulty input or other error
        if (cin.fail()){
            cout << endl << endl << "Unfortunately, the program has crashed." << endl
                << "Please restart the program." << endl << endl;
            exit(0);
        }
        investment *= (1+p1/100)*(1+p2/100)*(1+p3/100)*(1+p4/100);
        cout << fixed << setprecision(2)
             << "The current value of your investment is " << investment << "!" << endl
             << endl <<  "Do you want to do another calculation? (y/n): ";
        cin >> answer;
    } while (answer != "n");
    return 0;
}

