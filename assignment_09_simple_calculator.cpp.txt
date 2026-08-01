// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// Topic: Console-Based Simple Calculator
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// -----------------------------------------------------------------------------
// Arithmetic Functions
// -----------------------------------------------------------------------------
double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
    {
        return NAN;
    }

    return a / b;
}

int modulus(int a, int b)
{
    if (b == 0)
    {
        return -1;
    }

    return a % b;
}

double exponent(double a, double b)
{
    return pow(a, b);
}

// -----------------------------------------------------------------------------
// Display Menu
// -----------------------------------------------------------------------------
void displayMenu()
{
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------
int main()
{
    int choice;

    while (true)
    {
        displayMenu();

        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice == 7)
        {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7)
        {
            cout << "Error: Invalid choice. Please select a number from 1 to 7." << endl;
            continue;
        }

        if (choice == 5)
        {
            int num1, num2;

            cout << "Enter first number : ";
            cin >> num1;

            cout << "Enter second number: ";
            cin >> num2;

            if (num2 == 0)
            {
                cout << "Error: Cannot divide by zero." << endl;
            }
            else
            {
                cout << "Result: " << num1 << " % " << num2
                     << " = " << modulus(num1, num2) << endl;
            }
        }
        else
        {
            double num1, num2;

            cout << "Enter first number : ";
            cin >> num1;

            cout << "Enter second number: ";
            cin >> num2;

            cout << fixed << setprecision(2);

            switch (choice)
            {
                case 1:
                    cout << "Result: " << num1 << " + " << num2
                         << " = " << add(num1, num2) << endl;
                    break;

                case 2:
                    cout << "Result: " << num1 << " - " << num2
                         << " = " << subtract(num1, num2) << endl;
                    break;

                case 3:
                    cout << "Result: " << num1 << " * " << num2
                         << " = " << multiply(num1, num2) << endl;
                    break;

                case 4:
                    if (num2 == 0)
                    {
                        cout << "Error: Cannot divide by zero." << endl;
                    }
                    else
                    {
                        cout << "Result: " << num1 << " / " << num2
                             << " = " << divide(num1, num2) << endl;
                    }
                    break;

                case 6:
                    cout << "Result: " << num1 << " ^ " << num2
                         << " = " << exponent(num1, num2) << endl;
                    break;
            }
        }
    }

    return 0;
}