// Filename: Task8.cpp
// Created by Rickard Bolin on 2019-11-20.
//
// This program calculates and prints all prime numbers between 2 and 100.

#include <iostream>
using namespace std;

bool checkPrime(int n);

int main(){
    for (int i=2; i<=100; i++) {
        if (checkPrime(i)){
            cout << i << endl;
        }
    }
    return 0;
}

/**
 * Checks if n is a prime number.
 *
 * @param n - Arbitrary integer.
 */
bool checkPrime(int n){
    for (int j=2; j<n; j++){
        if(n%j == 0){
            return false;
        }
    }
    return true;
}