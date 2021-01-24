#include <iostream>
#include <cstring>

using namespace std;

const int BUFLEN = 100; // Max length	of	reading	buffer

void sort(char *friendList[], int n); // n	is	the	amount	of	elements

void print(char *friendList[], int n); // n	is	the	amount	of	elements

void terminate(char *friendList[], int n); // n	is	the	amount	of	elements

const int AMOUNT = 5;

int main() {
    char *friends[AMOUNT];//	Vector	with	AMOUNT	pcs	of string	pointers
    char buff[BUFLEN] = {""}; //	Creates	string	buffer (null terminated)
    int count = 0;

    while (count < AMOUNT) //	As	long	as	space	available	in	the	vector
    {
        cout << "Name a friend:	";
        cin.getline(buff, BUFLEN); //	Temporary	reading	into string	buffer
        friends[count] = new char[BUFLEN];
        copy(buff, buff + BUFLEN, friends[count]);
        ++count;
    }
    sort(friends, count); //	Sorts	the ‘count’ first	elements	of	the	vector	with	string	pointers
    print(friends, count); //	Prints	the	‘count’ first	names
    terminate(friends, count); //	Releases	all	allocated	memory	space
    return 0;
}

/**
This function sorts n first c-arrays in friendList
@param friendList - Vector containing c-arrays
@param n - The number of c-arrays in friendList
*/
void sort(char *friendList[], int n) {
    char *temp;
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (strncmp(friendList[i], friendList[i + 1], BUFLEN) > 0) {
                temp = friendList[i];
                friendList[i] = friendList[i + 1];
                friendList[i + 1] = temp;
            }
        }
    }
}

/**
This function prints n strings in friendList.
@param friendList - Vector containing c-arrays
@param n - The number of c-arrays in friendList
*/
void print(char *friendList[], int n) {
    for (int i = 0; i < n; i++) {
        cout << friendList[i] << endl;
    }
}

/**
This function returns all memory in a vector of c-arrays.
(friendList itself is not dynamically allocated, and thus needs no active handling)
@param friendList - Vector containing c-arrays
@param n - The number of c-arrays in friendList
*/
void terminate(char *friendList[], int n) {
    for (int i = 0; i < n; i++) {
        delete[] friendList[i];
    }
}
