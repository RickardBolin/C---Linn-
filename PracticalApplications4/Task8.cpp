// Filename: Task8.cpp
// Created by Rickard Bolin on 2019-12-11.
//
// This program asks the user for a date on the form YYYYMMDD and calculates
// the date of tomorrow on the same form.
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

bool leapYear(int year);

int daysInMonth(int year, int month);

int getDate();

void splitDate(int date, int &year, int &month, int &day);

bool checkFormat(int date);

int tomorrow(int date);

int main() {
    int date;
    char answer;
    do {
        system("clear");
        date = getDate();
        cout << "Tomorrow it is: " << tomorrow(date) << endl;
        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');
    return 0;
}

/**
A function used to calculate if a given year is a leap year or not
@param year, arbitrary integer.
@return true if leap year, otherwise false.
*/
bool leapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else {
        return (year % 4 == 0);
    }
}

/**
A function used to calculate the number of days in a given month
@param year, arbitrary positive integer
@param month, integer between 1 and 12
@return the number of days in a month
*/
int daysInMonth(int year, int month) {
    map<int, int> daysInMonth;
    daysInMonth[1] = 31;
    daysInMonth[2] = 28;
    daysInMonth[3] = 31;
    daysInMonth[4] = 30;
    daysInMonth[5] = 31;
    daysInMonth[6] = 30;
    daysInMonth[7] = 31;
    daysInMonth[8] = 31;
    daysInMonth[9] = 30;
    daysInMonth[10] = 31;
    daysInMonth[11] = 30;
    daysInMonth[12] = 31;
    int days = daysInMonth[month];
    if (leapYear(year) && month == 2) {
        days++;
    }
    return days;
}

/**
A function to get user input in the form of a date (YYYYMMDD)
@return date on the form YYYYMMDD
*/
int getDate() {
    bool badInput;
    int date;
    do {
        badInput = false;
        // Check for faulty input or other error while asking user for input
        cout << "Enter a date on the form YYYYMMDD: ";
        cin >> date;
        if (cin.fail() || date < 0 || !checkFormat(date)) {
            badInput = true;
            cout << "Invalid input, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (badInput);
    return date;
}

/**
A function used to split a date on the form YYYYMMDD into year, month and day.
@param date, integer on the form YYYYMMDD
@param year, reference to integer
@param month, reference to integer
@param day, reference to integer
*/
void splitDate(int date, int &year, int &month, int &day) {
    day = date % 100;
    date = date / 100;
    month = date % 100;
    year = date / 100;
}

/**
A function used to check if the date is formatted correctly.
@param date, integer on the form YYYYMMDD
@return true if correct format, otherwise false
*/
bool checkFormat(int date) {
    int year, month, day;
    splitDate(date, year, month, day);
    return (0 < month && month < 13 && 0 < day && day <= daysInMonth(year, month));
}

/**
A function used to calculate tomorrows date on the form YYYYMMDD.
@param date, integer on the form YYYYMMDD
@return tomorrows date on the form YYYYMMDD
*/
int tomorrow(int date) {
    int year, month, day;
    splitDate(date, year, month, day);
    if (day == daysInMonth(year, month)) {
        month++;
        day = 1;
        if (month == 13) {
            month = 1;
            year++;
        }
    } else {
        day++;
    }
    return (year * 100 + month) * 100 + day;
}
