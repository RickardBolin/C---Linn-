// Filename: Task5.cpp
// Created by Rickard Bolin on 2019-11-20.
//
// This program prints a pretty pattern.

#include <iostream>
using namespace std;

int main()
{
    for (int row=1; row<=8; row++){
        if(row%2 == 0){
            cout << " ";
        }
        for (int col=1; col<=8; col++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
