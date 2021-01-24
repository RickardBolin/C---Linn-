// Filename: Task4.cpp
// Created by Rickard Bolin on 2019-12-28.
//
// This program simulates the game Rock, Paper, Scissors.
#include <ctime>
#include <iostream>

using namespace std;

enum Moves {
    Stone, Scissors, Paper
};

int getCompMove();

int getPlayerMove();

int findWinner(Moves compMove, Moves playerMove);

string getMoveString(Moves move);

int main() {
    char answer;
    do {
        system("clear");
        srand(time(0));
        int compWins = 0;
        int myWins = 0;
        while (compWins < 10 && myWins < 10) {
            Moves compMove = Moves(getCompMove());
            Moves playerMove = Moves(getPlayerMove());
            cout << "Computer chose " << getMoveString(compMove) << endl;
            // If winner = 0; draw  winner = 1; Computer   winner = 2; Player
            int winner = findWinner(compMove, playerMove);
            if (winner == 0) {
                cout << "Equal!" << endl;
            } else if (winner == 1) {
                cout << "Computer won!" << endl;
                compWins++;
            } else {
                cout << "You won!" << endl;
                myWins++;
            }
            cout << "Score (you - computer): " << myWins << "-" << compWins << endl;
        }
        if (compWins == 10) {
            cout << "Computer won with " << compWins << " to " << myWins << endl;
        } else {
            cout << "You won with " << myWins << " to " << compWins << endl;
        }

        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
        cin.clear();
        cin.ignore(80, '\n');
    } while (answer == 'y' || answer == 'Y');
    return 0;
}

/**
This function gets the computer's move (0, 1 or 2)
@return the move
*/
int getCompMove() {
    return rand() % 3;
}

/**
This function gets the player's move (0, 1 or 2)
@return the player's move
*/
int getPlayerMove() {
    cout << "Your choice (Stone=0/Scissors=1/Paper=2): ";
    bool badInput;
    int choice;
    do {
        badInput = false;
        cin >> choice;
        if (cin.fail() || (choice != 0 && choice != 1 && choice != 2)) {
            badInput = true;
            cout << endl << "Invalid input, please choose again: ";
            cin.clear();
            cin.ignore(80, '\n');
        }
    } while (badInput);
    return choice;
}

/**
This function looks up who won in a "win-matrix".
@param compMove - The move the computer chose
@param playerMove - The move the player chose
@return an integer representing the winner.
*/
int findWinner(Moves compMove, Moves playerMove) {
    // Player 1: Computer, Player 2: Human
    int winMatrix[3][3] = {{0, 1, 2},
                           {2, 0, 1},
                           {1, 2, 0}};
    return winMatrix[compMove][playerMove];
}

/**
This function returns the "string-version" of the different moves.
@param move - a move from "Moves"
@return the move as a string
*/
string getMoveString(Moves move) {
    switch (move) {
        case Stone:
            return "Stone";
        case Scissors:
            return "Scissors";
        case Paper:
            return "Paper";
    }
}
