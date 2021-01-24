// Filename: Task3.cpp
// Created by Rickard Bolin on 2019-12-28.
//
// This program tests a few functions related to handling and converting
// times in a struct form and in pure minutes.
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

struct TimeType;

int toMinutes(TimeType &time);

TimeType toTime(int minutes);

TimeType timeDifference(TimeType &timeA, TimeType &timeB);

TimeType dynamicTimes();

void printTime(TimeType &time);

int main() {

    // Test toTime:
    int minutes = 100;
    TimeType testToTime = toTime(100); // Should become (1, 40)
    printTime(testToTime);

    // Test toMinutes:
    TimeType timeA = {3, 20}; // = 200 minutes
    int testToMinutes = toMinutes(timeA);
    cout << testToMinutes << endl;

    // Test timeDifference:
    TimeType timeB = {10, 15};
    TimeType timeC = {15, 10};
    TimeType timeD = timeDifference(timeB, timeC);
    printTime(timeD);

    // Test dynamicTimes():
    TimeType maxDiff = dynamicTimes();
    printTime(maxDiff);
    return 0;
}

/**
A struct that holds a time, separated into hours and minutes.
*/
struct TimeType {
    int hour;
    int min;
};

/**
This function calculates calculates the number of minutes of a time on the
form hh:mm stored in the struct "TimeType".
@param time - struct holding hours and minutes
@return the number of minutes
*/
int toMinutes(TimeType &time) {
    return time.hour * 60 + time.min;
}

/**
This function converts minutes to a time on the form hh:mm and stores it in a struct.
@param minutes - arbitrary integer
@return a struct containing the number of hours and minutes.
*/
TimeType toTime(int minutes) {
    return {minutes / 60, minutes - 60 * (minutes / 60)};
}

/**
This function calculates the difference between two times.
@param timeA - arbitrary time of type TimeType
@param timeB - arbitrary time of type TimeType
@return time difference in a struct that stores hours and minutes.
*/
TimeType timeDifference(TimeType &timeA, TimeType &timeB) {
    return toTime(abs(toMinutes(timeA) - toMinutes(timeB)));
}

/**
This function generates 200 random times and calculates the maximum time
difference between any two of the generated times.
@return struct containing the maximum time difference in hours and minutes.
*/
TimeType dynamicTimes() {
    int minutes;
    const int NBTIMES = 200;
    // Setting max value of minutes to 1e4 to keep everything at a reasonable size.
    const int MAX = 1e4;
    TimeType minTime = toTime(MAX);
    TimeType maxTime = toTime(0);
    srand(time(0));
    TimeType *times = new TimeType[NBTIMES];
    for (int i = 0; i < NBTIMES; i++) {
        // Generate random integer in the range 0::MAX
        minutes = rand() % MAX;
        times[i] = toTime(minutes);
        // If larger than current max, set it to new max.
        if (minutes > toMinutes(maxTime)) {
            maxTime = times[i];
        }
            // If smaller than current min, set it to new min.
        else if (minutes < toMinutes(minTime)) {
            minTime = times[i];
        }
    }
    return timeDifference(maxTime, minTime);
}

/**
This function prints a time of the form TimeType as "hh:mm".
@param time - arbitrary time of the type TimeType
*/
void printTime(TimeType &time) {
    cout << setfill('0') << setw(2) << time.hour << ":"
         << setfill('0') << setw(2) << time.min << endl;
}
