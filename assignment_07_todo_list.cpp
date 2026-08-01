// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// Topic: Console-Based To-Do List Application
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -----------------------------------------------------------------------------
// Add a Task
// -----------------------------------------------------------------------------
void addTask(vector<string>& tasks)
{
    string task;

    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);

    tasks.push_back(task);

    cout << "Task added: \"" << task << "\"" << endl;
}

// -----------------------------------------------------------------------------
// View All Tasks
// -----------------------------------------------------------------------------
void viewTasks(const vector<string>& tasks)
{
    if (tasks.empty())
    {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    cout << "\nYour Tasks:" << endl;

    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// -----------------------------------------------------------------------------
// Delete a Task
// -----------------------------------------------------------------------------
void deleteTask(vector<string>& tasks)
{
    if (tasks.empty())
    {
        cout << "There are no tasks to delete." << endl;
        return;
    }

    cout << "\nYour Tasks:" << endl;

    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }

    int taskNumber;

    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size())
    {
        cout << "Task \"" << tasks[taskNumber - 1] << "\" has been removed." << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    }
    else
    {
        cout << "Error: Invalid task number." << endl;
    }
}

// -----------------------------------------------------------------------------
// Display Menu
// -----------------------------------------------------------------------------
void displayMenu()
{
    cout << "\n============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------
int main()
{
    vector<string> tasks;
    int choice;

    while (true)
    {
        displayMenu();

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addTask(tasks);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                deleteTask(tasks);
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