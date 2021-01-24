// Filename: Task7.cpp
// Created by Rickard Bolin on 2019-11-20.
//
// This program calculates a score out of 9 decimal values, provided by the user.

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {

    string answer;
    double current;

    do{
        double largest = numeric_limits<double>::min();
        double smallest = numeric_limits<double>::max();
        double sum = 0;
        for (int i=0; i<9; i++){
            cout << "Enter an score: ";
            // Check for faulty input or other error while asking user for input
            label:
            cin >> current;
            if (cin.fail()){
                cout << "Incorrect input, please enter another score: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                goto label;
            }
            sum += current;
            if (current > largest){
                largest = current;
            }
            if (current < smallest){
                smallest = current;
            }
        }
        double finalScore = (sum - largest - smallest)/7;
        cout << "The final score is " << setprecision(2) << finalScore << "!" << endl;
        cout << "Do you want to go again? (y/n): ";
        cin >> answer;
    } while (answer != "n");
    return 0;
}
