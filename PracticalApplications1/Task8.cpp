// Filename: Task8.cpp
// Created by Rickard Bolin on 2019-11-05.
//
// This program calculates the perceived temperature after asking
// the user to input temperature and wind speed.
//
// OBS! Couldn't access the link in the exercise description, but I found a PDF
//      that I think contains the same information. The link to the PDF is:
//      https://www.smhi.se/polopoly_fs/1.6392!/webb_vindavkylning.pdf
//

#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string answer;
    double T, v;

    do{
        do{
            cout << "Enter temperature (in Celsius): ";
            cin >> T;
            cout << "Enter wind speed (in m/s): ";
            cin >> v;
            // Check for faulty input or other error
            if (cin.fail()){
                cout << endl << endl << "Unfortunately, the program has crashed." << endl <<
                     "You might have entered the wrong data type or a too large number. " << endl << endl <<
                     "Please restart the program." << endl << endl;
                exit(0);
            }
            if (v < 0.5){
                cout << "The formula doesn't work for wind speeds below 0.5°C. " << endl
                     << "Please enter a higher wind speed." << endl << endl;
            }
        } while (v < 0.5);


        int T_eff = round(13.12+0.6215*T - 13.956*pow(v, 0.16)+0.48669*T*pow(v,0.16));
        cout << T << "°C and " << v << " m/s gives the perceived temperature " << T_eff << "°C"
             << endl << endl <<  "Do you want to do another calculation? (y/n): ";
        cin >> answer;
    } while (answer != "n");
    return 0;
}
