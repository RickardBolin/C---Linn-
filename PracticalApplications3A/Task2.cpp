// Filename: Task2.cpp
// Created by Rickard Bolin on 2019-12-03.
//
// Takes an integer N between 1 and 30 as input, then asks the user for N more numbers
// plus a test number for comparison. Then it prints how many and which of the entered
// numbers are less than the test number. Last, it prints the numbers in reversed order.
#include <string>
#include <iostream>

using namespace std;

int main() {
    const int SIZE = 30;
    int N;
    bool badInput;

    cout << "Enter a positive integer with value not more than 30: ";
    do {
        // Check for faulty input or other error while asking user for input
        badInput = false;
        cin >> N;
        if (cin.fail() || N > SIZE || N <= 0) {
            cout << "Incorrect input, please enter a five-digit number:" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            badInput = true;
        }
    } while (badInput);

    int numbers[N];
    for (int i = 0; i < N; i++) {
        do {
            badInput = false;
            cout << "Number " << i + 1 << ": ";
            cin >> numbers[i];
            if (cin.fail()) {
                cout << "Incorrect input, please enter a digit!" << endl;
                badInput = true;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (badInput);
    }

    int test;
    cout << "Enter the test number for comparison: ";
    do {
        badInput = false;
        // Check for faulty input or other error while asking user for input
        cin >> test;
        if (cin.fail()) {
            cout << "Incorrect input, please enter a number:" << endl;
            badInput = true;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (badInput);

    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (numbers[i] < test) {
            counter++;
        }
    }

    cout << "There are " << counter << " numbers that are lower than " << test << ", which are: ";
    for (int i = 0; i < N; i++) {
        if (numbers[i] < test) {
            cout << numbers[i] << ", ";
        }
    }

    cout << endl << "Numbers in the reverse order are as follows:" << endl;
    for (int i = N - 1; i >= 0; i--) {
        cout << numbers[i] << endl;
    }
    return 0;
}
