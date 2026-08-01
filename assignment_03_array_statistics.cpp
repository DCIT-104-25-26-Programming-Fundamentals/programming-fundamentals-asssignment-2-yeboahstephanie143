// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// Topic: Arrays, Loops, and Functions
// =============================================================================

#include <iostream>
using namespace std;

// Function to calculate the sum
int calculateSum(int numbers[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += numbers[i];
    }

    return total;
}

// Function to calculate the average
double calculateAverage(int numbers[], int size)
{
    int total = calculateSum(numbers, size);
    return (double)total / size;
}

// Function to find the maximum value
int findMaximum(int numbers[], int size)
{
    int maximum = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }

    return maximum;
}

// Function to find the minimum value
int findMinimum(int numbers[], int size)
{
    int minimum = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
    }

    return minimum;
}

// Main function
int main()
{
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: Number of values must be greater than 0." << endl;
        return 0;
    }

    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum: " << calculateSum(numbers, n) << endl;
    cout << "Average: " << calculateAverage(numbers, n) << endl;
    cout << "Maximum: " << findMaximum(numbers, n) << endl;
    cout << "Minimum: " << findMinimum(numbers, n) << endl;

    return 0;
}