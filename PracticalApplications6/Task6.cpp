// Filename: Task6.cpp
// Created by Rickard Bolin on 2020-01-07.
//
// This program calculates surface measurement statistics from
// a .txt-file containing measurements and then prints the stats.
#include <fstream>
#include <iostream>
#include <math.h>
#include <float.h>
#include <iomanip>
using namespace std;

bool calcSurfaceStats(const char *surfaceMeasurements);

int main(){
    calcSurfaceStats("./files/surfacedata.txt");
    return 0;
}

/**
This function calculates the arithmetic mean value (Ra), root mean square average (Rq)
and maximum roughness height of surface measurements stored in the file surfaceMeasurements
@param surfaceMeasurements - file containing measurements
@return true if the file opened, otherwise false
*/
bool calcSurfaceStats(const char *surfaceMeasurements){

    ifstream infile;
    infile.open(surfaceMeasurements);

    if (!infile.is_open()){
        cout << "Failed to open the file " << surfaceMeasurements << "!" << endl;
        return false;
    }

    int counter = 0;
    double num, absSum = 0, squareSum = 0, max = -DBL_MAX, min = DBL_MAX;

    while (infile >> num){
        absSum += abs(num);
        squareSum += pow(num, 2);
        if (num > max){
            max = num;
        }
        if (num < min){
            min = num;
        }
        counter++;
    }

    double arithmeticMean = absSum/counter;
    double rootMeanSquareAvg = sqrt(squareSum/counter);
    double maxRoughnessHeight = abs(max) + abs(min);

    cout << fixed << setprecision(3)
         << "Arithmetic mean value:    " << arithmeticMean << endl
         << "Root mean square average: " << rootMeanSquareAvg << endl
         << "Maximum roughness height: " << maxRoughnessHeight << endl;

    infile.close();
    return true;
}
