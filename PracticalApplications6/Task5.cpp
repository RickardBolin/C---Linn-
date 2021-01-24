// Filename: Task5.cpp
// Created by Rickard Bolin on 2020-01-06.
//
// This program reads the text file and creates a new file containing all messages
// coming from a pre-specified phone number.
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

bool senderFilter(char *logFileName, char *resultFileName, const char *sender);

int main() {
    char logFileName[] = "./files/smslog_eng.txt";
    char resultFileName[] = "./files/result.txt";
    const char sender[] = "0702-235689";
    senderFilter(logFileName, resultFileName, sender);
    return 0;
}

/**
This function reads the text file and creates a new file containing all messages
coming from the phone number specified by the parameter sender.
@param logFileName – a string containing the name of the file with the SMS log
@param resultFileName – a string with the name of the file to be created
@param sender – a string containing the phone number that is to be filtered out
@return true if all went well when creating the file, otherwise false
*/
bool senderFilter(char *logFileName, char *resultFileName, const char *sender) {

    const int SIZE = 256;
    ifstream infile(logFileName);
    ofstream outfile(resultFileName);

    if (!infile.is_open() || !outfile.is_open()) {
        cout << "Failed to open one of the files!" << endl;
        return false;
    }

    char log_sender[SIZE];
    char receiver[SIZE];
    char date[SIZE];
    char message[SIZE];
    // Read until EOF found, which returns 0
    while (infile.getline(log_sender, SIZE, '\n')) {
        infile.getline(receiver, SIZE, '\n');
        infile.getline(date, SIZE);
        infile.getline(message, SIZE);

        // Numbers are only 11 characters long, only check first 11 chars
        if (strncmp(sender, log_sender, 11) == 0) {
            outfile << log_sender << endl
                    << receiver << endl
                    << date << endl
                    << message;
        }
    }
    infile.close();
    outfile.close();
    return true;
}
