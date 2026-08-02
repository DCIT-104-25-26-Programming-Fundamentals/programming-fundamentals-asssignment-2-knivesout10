// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
// TASK: Matrix Operations
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Helper function to input matrix elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string name) {
    cout << "\nEnter elements for Matrix " << name << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Helper function to print a matrix in aligned grid form
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose a Matrix
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

// PART B: Add Two Matrices
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply Two Matrices
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rA, int cA, int cB) {
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "===========================================\n";
    cout << "          MATRIX OPERATIONS MENU           \n";
    cout << "===========================================\n";
    cout << "1. Part A: Transpose a Matrix\n";
    cout << "2. Part B: Add Two Matrices\n";
    cout << "3. Part C: Multiply Two Matrices\n";
    cout << "Choose an option (1-3): ";
    cin >> choice;

    if (choice == 1) {
        // --- PART A ---
        int rows, cols;
        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int A[MAX_SIZE][MAX_SIZE];
        int transposed[MAX_SIZE][MAX_SIZE];

        inputMatrix(A, rows, cols, "A");

        transposeMatrix(A, transposed, rows, cols);

        cout << "\nOriginal Matrix:\n";
        printMatrix(A, rows, cols);

        cout << "\nTransposed Matrix:\n";
        printMatrix(transposed, cols, rows);

    } else if (choice == 2) {
        // --- PART B ---
        int rows, cols;
        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        inputMatrix(A, rows, cols, "A");
        inputMatrix(B, rows, cols, "B");

        addMatrices(A, B, result, rows, cols);

        cout << "\nMatrix A + Matrix B:\n";
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        // --- PART C ---
        int rA, cA, rB, cB;
        cout << "\nFor Matrix A:";
        cout << "\nEnter number of rows: ";
        cin >> rA;
        cout << "Enter number of columns: ";
        cin >> cA;

        cout << "\nFor Matrix B:";
        cout << "\nEnter number of rows: ";
        cin >> rB;
        cout << "Enter number of columns: ";
        cin >> cB;

        if (cA != rB) {
            cout << "\nError: Columns of Matrix A (" << cA 
                 << ") must equal Rows of Matrix B (" << rB << ") to multiply!\n";
            return 1;
        }

        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        inputMatrix(A, rA, cA, "A");
        inputMatrix(B, rB, cB, "B");

        multiplyMatrices(A, B, result, rA, cA, cB);

        cout << "\nMatrix A x Matrix B:\n";
        printMatrix(result, rA, cB);

    } else {
        cout << "\nInvalid choice program exiting.\n";
    }

    return 0;
}