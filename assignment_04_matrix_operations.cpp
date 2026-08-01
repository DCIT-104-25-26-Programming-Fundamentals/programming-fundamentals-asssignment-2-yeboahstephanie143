// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// Topic: 2D Arrays, Nested Loops, and Functions
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// -----------------------------------------------------------------------------
// Function to read a matrix
// -----------------------------------------------------------------------------
void readMatrix(int matrix[10][10], int rows, int cols, string name)
{
    cout << "\nEnter values for Matrix " << name << ":" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// Function to display a matrix
// -----------------------------------------------------------------------------
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// PART A - Transpose Matrix
// -----------------------------------------------------------------------------
void transposeMatrix(int matrix[10][10], int transpose[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART B - Add Matrices
// -----------------------------------------------------------------------------
void addMatrices(int matrix1[10][10], int matrix2[10][10],
                 int result[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART C - Multiply Matrices
// -----------------------------------------------------------------------------
void multiplyMatrices(int A[10][10], int B[10][10],
                      int result[10][10],
                      int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------
int main()
{
    int matrixA[10][10], matrixB[10][10];
    int result[10][10], transpose[10][10];

    int rows, cols;

    // =========================================================
    // PART A
    // =========================================================
    cout << "========== PART A : TRANSPOSE ==========" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrixA, rows, cols, "A");

    transposeMatrix(matrixA, transpose, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrixA, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transpose, cols, rows);

    // =========================================================
    // PART B
    // =========================================================
    cout << "\n========== PART B : MATRIX ADDITION ==========" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrixA, rows, cols, "1");
    readMatrix(matrixB, rows, cols, "2");

    addMatrices(matrixA, matrixB, result, rows, cols);

    cout << "\nResult of Addition:" << endl;
    displayMatrix(result, rows, cols);

    // =========================================================
    // PART C
    // =========================================================
    cout << "\n========== PART C : MATRIX MULTIPLICATION ==========" << endl;

    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;

    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    readMatrix(matrixA, rowsA, colsA, "A");

    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;

    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "\nError: Matrix multiplication is not possible." << endl;
        cout << "Columns of Matrix A must equal rows of Matrix B." << endl;
        return 0;
    }

    readMatrix(matrixB, rowsB, colsB, "B");

    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);

    cout << "\nResult of Multiplication:" << endl;
    displayMatrix(result, rowsA, colsB);

    return 0;
}