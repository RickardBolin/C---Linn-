// Filename: Task7.cpp
// Created by Rickard Bolin on 2019-12-28.
//
// This program asks the user to input two matrices and performs matrix
// multiplication on them.
#include <iostream>
#include <iomanip>

using namespace std;

const int MAXDIM = 5;
typedef double Matrix[MAXDIM][MAXDIM];

void readDimensions(int &rows, int &cols);

void readMatrix(Matrix M, int row, int col);

void multMatrix(const Matrix A, const Matrix B, Matrix C, int m, int n, int p);

void printMatrix(const Matrix M, int row, int col);

int main() {
    char answer;
    do {
        Matrix A, B, C;
        int rowsA, colsA, rowsB, colsB;
        cout << "Enter dimension of matrix A (row x col) with space between: ";
        readDimensions(rowsA, colsA);
        cout << "Enter matrix A in free format:" << endl;
        readMatrix(A, rowsA, colsA);
        cout << "Enter dimension of matrix B (row x col) with space between: ";
        readDimensions(rowsB, colsB);
        cout << "Enter matrix B in free format:" << endl;
        readMatrix(B, rowsB, colsB);
        if (colsA == rowsB) {
            cout << "---------------------------" << endl
                 << "ANSWER" << endl;
            multMatrix(A, B, C, rowsA, colsB, colsA);
            printMatrix(C, rowsA, colsB);
        } else {
            cout << "Dimensions doesn't match, can't perform matrix multiplication!" << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }

        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
        cin.clear();
        cin.ignore(80, '\n');
    } while (answer == 'y' || answer == 'Y');
    return 0;
}

/**
This function asks the user to input a matrix of size rows*cols
@param M   - The matrix where the user input is stored
@param row - Number of rows in M
@param col - Number of columns in M
*/
void readMatrix(Matrix M, int row, int col) {
    bool badInput;
    do {
        badInput = false;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                cin >> M[r][c];
            }
        }
        if (cin.fail()) {
            cout << "Invalid input, try again:" << endl;
            badInput = true;
            cin.clear();
            cin.ignore(80, '\n');
        }
    } while (badInput);
}

/**
This function asks the user to input the dimensions of a matrix
@param rows - The number of rows
@param cols - The number of columns
*/
void readDimensions(int &rows, int &cols) {
    bool badInput;
    do {
        badInput = false;
        cin >> rows;
        cin >> cols;
        if (cin.fail() || rows < 0 || rows > MAXDIM || cols < 0 || cols > MAXDIM) {
            badInput = true;
            cout << endl << "Invalid input, please choose again: ";
            cin.clear();
            cin.ignore(80, '\n');
        }
    } while (badInput);
}

/**
This function performs matrix multiplication of matrix A and B and stores in C
@param A - First matrix to be multiplied
@param B - Second matrix to be multiplied
@param C - The result of the multiplication
@param m - The number of rows in A
@param n - The number of columns in B
@param p - The number of columns in A and rows in B
*/
void multMatrix(const Matrix A, const Matrix B, Matrix C, int m, int n, int p) {
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            C[r][c] = 0;
            for (int i = 0; i < p; i++) {
                C[r][c] += A[r][i] * B[i][c];
            }
        }
    }
}

/**
This function prints the matrix M.
@param M   - The matrix to be printed
@param row - The number of rows in M
@param col - The number of cols in M
*/
void printMatrix(const Matrix M, int row, int col) {
    cout << fixed << setprecision(1);
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << setw(10) << M[r][c] << " ";
        }
        cout << endl;
    }
}
