// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// Topic: Functions and Loops
// =============================================================================

#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int number)
{
    if (number < 2)
    {
        return false;
    }

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

// Main function
int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number))
    {
        cout << number << " is a prime number." << endl;
    }
    else
    {
        cout << number << " is NOT a prime number." << endl;
    }

    return 0;
}