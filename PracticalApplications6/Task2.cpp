// Filename: Task2.cpp
// Created by Rickard Bolin on 2020-01-06.
//
// This program calculates some statistics of a file containing integers.
#include <fstream>
#include <iostream>

using namespace std;

bool calcFileStats(const char *filename);

int main() {
    calcFileStats("./files/integers.txt");
    return 0;
}

/**
This function calculates the sum, mean and max value of
all integers in a file.
@param filename - file containing integers
@return true if the file opened, otherwise false
*/
bool calcFileStats(const char *filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Failed to open the file " << filename << "!" << endl;
        return false;
    }

    int num, counter = 0, max = 0;
    double sum = 0, mean;

    while (infile >> num) {
        sum += num;
        if (num > max) {
            max = num;
        }
        counter++;
    }
    mean = sum / counter;
    cout << "Sum:  " << sum << endl
         << "Mean: " << mean << endl
         << "Max:  " << max << endl;

    infile.close();
    return true;
}
