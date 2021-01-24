// Filename: Task3.cpp
// Created by Rickard Bolin on 2019-12-11.
//
// This program calculates x to the power of y, where x and y are entered by the user.
#include <iostream>
#include <iomanip>
using namespace std;

double power(double x, double y=2);

int main() {

    for (int i = 0; i < 10; i++){
        cout << power(2, i) << " "; // prints 2 raised to the power of i
    }
    cout << endl;
    cout << power(3) << endl; // will print 9
    cout << power(4) << endl; // will print 16
    cout << power(5) << endl; // will print 25
    return 0;
}

/**
This function calculates x to the power of y.
@param x - arbitrary double
@param y - arbitrary double
@return x to the power of y
*/
double power(double x, double y){
    if (y == 0){
        return 1;
    } else {
        double result = x;
        for (int i = 1; i < y; i++) {
            result *= x;
        }
        return result;
    }
}
