// Filename: Task1.cpp
// Created by Rickard Bolin on 2019-12-28.
//
// This program reads user input until the user inputs something else
// than a number, then prints the entered numbers.
#include<iostream>

using namespace std;

int main() {

    int counter = 0;
    int *ptr = nullptr;
    int nr;
    cout << "Enter integer numbers to store (Stop with “Esc” key or non-numeric value): ";
    while (cin >> nr) {
        int *newPtr = new int[counter * sizeof(int) + 1];
        for (int i = 0; i < counter; i++) {
            newPtr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newPtr;
        ptr[counter] = nr;
        counter++;
    }

    if (!cin) {
        cin.clear();
        cin.ignore(80, '\n');
    }

    cout << "You entered: ";
    for (int i = 0; i < counter; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
    delete[] ptr;
    ptr = nullptr;
}
