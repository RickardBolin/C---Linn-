// Filename: Task6.cpp
// Created by Rickard Bolin on 2019-12-28.
//
// This program approximates Pi with a Monte Carlo method
#include <ctime>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <iostream>

using namespace std;

struct Coord // Data representation of a point where the arrow hits
{
    double x, y;
};

void throwSeries(int n);

Coord throwArrow();

bool below(Coord coord);

const double R = 100; // Radius of the circle (=square side) is determined here

int main() {
    srand(time(0));
    cout << setw(6) << "n" << setw(7) << "pi" << setw(15) << "Rel. fault" << endl
         << "------|----------|----------" << endl;
    for (int i = 100; i <= 10000; i += 100) {
        throwSeries(i);
    }
    return 0;
}

/**
This function "throws an arrow" by generating two doubles in the range 0 to R
@return struct containing two doubles in the range 0 to R
*/
Coord throwArrow() {
    // Generates two random numbers between 0 and R and returns them in a struct
    return {rand() / (RAND_MAX / R), rand() / (RAND_MAX / R)};
}

/**
This function checks if a coordinate pair lies inside or
outside a circle radius R.
@param coord - struct containing a coordinate pair
@return true if inside circle, otherwise false
*/
bool below(Coord coord) {
    return sqrt(pow(coord.x, 2) + pow(coord.y, 2)) < R;
}

/**
This function performs n iterations of "throwArrow", approximates pi,
calculates the relative fault and then prints the calculated values.
@param n - The number of throws to be performed
*/
void throwSeries(int n) {
    int belowCount = 0;
    for (int i = 0; i < n; i++) {
        if (below(throwArrow())) {
            belowCount++;
        }
    }
    cout << fixed << setw(6) << n << setw(11)
         << setprecision(5) << 4.0 * belowCount / n << setw(11)
         << setprecision(1) << 100 * (4.0 * belowCount / n - M_PI) / M_PI << endl;
}
