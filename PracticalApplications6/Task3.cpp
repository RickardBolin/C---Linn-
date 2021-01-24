// Filename: Task3.cpp
// Created by Rickard Bolin on 2020-01-06.
//
// This program reads measurements from a .dat file and writes the read
// temperature and time to a .txt-file.

//
// I'm not sure if you'll be having the same problem as me when writing to
// A.txt since we might use different compilers, but my compiler insists of
// writing the date as "  6" instead of " 06". While looking for a solution
// on stackoverflow, I saw that the implementation of asctime differs a bit
// between compilers when it comes to using zero-padding or space-padding
// on the date.
//
// I couldn't figure out if this was a problem you wanted me to solve or if
// it is something that I could ignore. I went with ignoring the problem,
// since the solution I would've implemented would be pretty simple but ugly,
// just checking if the date is one or two digits long and pad with zero if
// digits=2, so I didn't feel like it was necessary.
//
// Hopefully I didn't miss a part of the task for ignoring this. If so, sorry!
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

bool getMeasurements(const char *inf, const char *outf);

struct DataRecord {
    char logger; //	Define	logging	Point	A,	B,	C,	…
    double temp; // Logged	Temperature
    time_t locTime; // Local	Time
};

int main() {
    getMeasurements("./files/timelog.dat", "./files/A.txt");
    return 0;
}

/**
This function reads measurements from a .dat file and writes the read
temperature and time to a .txt-file.
@param inf - the infile that will be read from
@param outf - the outfile that will be written to
@return true if both files opened, otherwise false
*/
bool getMeasurements(const char *inf, const char *outf) {
    // Open the infile which we read from
    ifstream infile;
    infile.open(inf, ios_base::binary);
    if (!infile.is_open()) {
        cout << "Failed to open the infile " << inf << "!" << endl;
        return false;
    }

    // Open the outfile that we write to
    ofstream outfile;
    outfile.open(outf, ios_base::binary);
    if (!outfile.is_open()) {
        cout << "Failed to open the outfile " << outf << "!" << endl;
        return false;
    }

    outfile << "Data A" << endl;
    DataRecord value;
    // Read though the infile and write the data with logger 'A' to A.txt
    while (infile.read((char *) &value, sizeof(value))) {
        if (value.logger == 'A') {
            outfile << fixed << setprecision(1) << value.temp << ","
                    << asctime(localtime(&value.locTime));
        }
    }
    infile.close();
    outfile.close();
    return true;
}
