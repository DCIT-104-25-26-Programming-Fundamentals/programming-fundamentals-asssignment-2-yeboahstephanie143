// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// Topic: Student Record Management System
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// -----------------------------------------------------------------------------
// Student Structure
// -----------------------------------------------------------------------------
struct Student
{
    string name;
    int id;
    vector<double> scores;
};

// -----------------------------------------------------------------------------
// Calculate Average
// -----------------------------------------------------------------------------
double calculateAverage(const vector<double>& scores)
{
    double total = 0;

    for (int i = 0; i < scores.size(); i++)
    {
        total += scores[i];
    }

    return total / scores.size();
}

// -----------------------------------------------------------------------------
// Add Student
// -----------------------------------------------------------------------------
void addStudent(vector<Student>& students)
{
    Student student;

    cin.ignore();

    cout << "Student name: ";
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    // Check for duplicate ID
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == student.id)
        {
            cout << "Error: Student ID already exists." << endl;
            return;
        }
    }

    int numScores;

    cout << "How many scores? ";
    cin >> numScores;

    if (numScores <= 0)
    {
        cout << "Error: Number of scores must be greater than 0." << endl;
        return;
    }

    for (int i = 0; i < numScores; i++)
    {
        double score;

        cout << "Enter score " << i + 1 << ": ";
        cin >> score;

        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

// -----------------------------------------------------------------------------
// Display All Students
// -----------------------------------------------------------------------------
void displayStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student records found." << endl;
        return;
    }

    cout << "\n-----------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name"
         << setw(15) << "ID"
         << setw(25) << "Scores"
         << "Average" << endl;

    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < students.size(); i++)
    {
        cout << left << setw(20) << students[i].name
             << setw(15) << students[i].id;

        for (int j = 0; j < students[i].scores.size(); j++)
        {
            cout << students[i].scores[j];

            if (j != students[i].scores.size() - 1)
            {
                cout << ", ";
            }
        }

        cout << setw(10) << "";

        cout << fixed << setprecision(2)
             << calculateAverage(students[i].scores) << endl;
    }

    cout << "-----------------------------------------------------------------------" << endl;
}

// -----------------------------------------------------------------------------
// Calculate Average for One Student
// -----------------------------------------------------------------------------
void studentAverage(const vector<Student>& students)
{
    int id;

    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << fixed << setprecision(2);
            cout << students[i].name
                 << "'s average score: "
                 << calculateAverage(students[i].scores)
                 << endl;

            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

// -----------------------------------------------------------------------------
// Display Menu
// -----------------------------------------------------------------------------
void displayMenu()
{
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------
int main()
{
    vector<Student> students;
    int choice;

    while (true)
    {
        displayMenu();

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                studentAverage(students);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Error: Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}