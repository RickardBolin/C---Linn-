// Filename: Task3.cpp
// Created by Rickard Bolin on 2019-11-20.
//
// This program prints the product of all odd integers between 1 and 15.

#include <iostream>
using namespace std;

int main()
{
    int product = 1;
    for (int i = 1; i<=15; i+=2){
        product *= i;
    }
    cout << "The product of all odd integers between 1 and 15 is " << product << "." << endl;
    return 0;
}
