// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// Topic: Loops and Functions
// =============================================================================

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// PART A - Print a Single Multiplication Table
// -----------------------------------------------------------------------------
void singleTable(int number)
{
    cout << "\nMultiplication Table for " << number << ":" << endl;

    for (int i = 1; i <= 12; i++)
    {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}

// -----------------------------------------------------------------------------
// PART B - Print Multiplication Tables from 1 to N
// -----------------------------------------------------------------------------
void multipleTables(int n)
{
    for (int number = 1; number <= n; number++)
    {
        cout << "\nMultiplication Table for " << number << ":" << endl;

        for (int i = 1; i <= 12; i++)
        {
            cout << number << " x " << i << " = " << number * i << endl;
        }

        cout << "---------------------------" << endl;
    }
}

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------
int main()
{
    int number, n;

    // Part A
    cout << "Enter a number: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Error: Number must be a positive integer." << endl;
        return 0;
    }

    singleTable(number);

    // Part B
    cout << "\nEnter N to print tables from 1 to N: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    multipleTables(n);

    return 0;
}