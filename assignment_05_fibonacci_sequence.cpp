// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// Topic: Loops, Sequences, and Functions
// =============================================================================

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// PART A - Print the First N Fibonacci Terms
// -----------------------------------------------------------------------------
void printFibonacci(int n)
{
    int first = 0;
    int second = 1;
    int next;

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++)
    {
        cout << first << " ";

        next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
}

// -----------------------------------------------------------------------------
// PART B - Check if a Number is a Fibonacci Number
// -----------------------------------------------------------------------------
bool isFibonacci(int number)
{
    if (number < 0)
    {
        return false;
    }

    int first = 0;
    int second = 1;
    int next;

    while (first < number)
    {
        next = first + second;
        first = second;
        second = next;
    }

    return first == number;
}

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------
int main()
{
    int n, number;

    // Part A
    cout << "How many terms? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: Number of terms must be a positive integer." << endl;
        return 0;
    }

    printFibonacci(n);

    // Part B
    cout << "\nEnter a number to check: ";
    cin >> number;

    if (isFibonacci(number))
    {
        cout << number << " is a Fibonacci number." << endl;
    }
    else
    {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}