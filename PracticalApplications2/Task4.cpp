// Filename: Task4.cpp
// Created by Rickard Bolin on 2019-11-20.
//
// This program prints a multiplication table between 1 and the user input.

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    int n;
    cout << "Enter an integer: ";
    // Check for faulty input or other error while asking user for input
    label:
    cin >> n;
    if(cin.fail()){
            cout << "Incorrect input, please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto label;
    }
    cout << "Multiplication table" << endl <<
         "===============================" << endl <<
         setw(3) << "n" << setw(7) << "10*n" <<
         setw(7) << "100*n" << setw(7) << "1000*n" << endl <<
         "-------------------------------" << endl;
    for (int i=1; i <=n; i++){
        cout << setw(3) << i << setw(7) << i*10 <<
        setw(7) << i*100 << setw(7) << i*1000 << endl;
    }
    return 0;
}

