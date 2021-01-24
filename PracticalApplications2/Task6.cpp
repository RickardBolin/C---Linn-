// Filename: Task6.cpp
// Created by Rickard Bolin on 2019-11-20.
//
// This program asks the user for 10 integers and prints the second largest of them.

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {

    string answer;
    int current;

    do{
        int largest = 0;
        int secondLargest = 0;
        for (int i=0; i<10; i++){
            cout << "Enter an integer: ";
            // Check for faulty input or other error while asking user for input
            label:
                cin >> current;
                if (cin.fail()){
                    cout << "Incorrect input, please enter an integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    goto label;
                }
            if (current > largest){
               secondLargest = largest;
               largest = current;
            }
            else if (current > secondLargest){
               secondLargest = current;
            }
        }

        cout << "The second largest integer you entered was " << secondLargest << "!" << endl;
        cout << "Do you want to go again? (y/n): ";
        cin >> answer;
    } while (answer != "n");
    return 0;
}


