// Filename: Task1.cpp
// Created by Rickard Bolin on 2020-01-06.
//
// This program asks the user to input personal details, then writes
// them to a csv-file.
#include <fstream>
#include <iostream>

using namespace std;

bool getPersonalDetails(const char *filename);

int main() {
    getPersonalDetails("./files/PersonalDetails.csv");
    return 0;
}

/**
This function asks the user to input personal details, then writes
them to a csv-file.
@param filename - the file to write to
@return true if the file opened/got created, otherwise false
*/
bool getPersonalDetails(const char *filename) {
    ofstream outfile;
    outfile.open(filename, ios_base::app);
    if (!outfile.is_open()) {
        cout << "Failed to open the file " << filename << "!" << endl;
        return false;
    }

    string first, last, nr;
    char answer;
    do {
        cout << "Enter first name: ";
        getline(cin, first);
        cout << "Enter last name: ";
        getline(cin, last);
        cout << "Enter phone number: ";
        getline(cin, nr);
        outfile << first << "," << last << "," << nr << endl;

        cout << "Do you want to enter details for another person (y/n)? ";
        cin >> answer;
        cin.clear();
        cin.ignore(80, '\n');
    } while (answer == 'y' || answer == 'Y');
    outfile.close();
    return true;
}
