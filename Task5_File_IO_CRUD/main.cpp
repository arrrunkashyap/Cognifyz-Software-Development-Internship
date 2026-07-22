#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

struct Task
{
    int id;
    string title;
    bool completed;
};

vector<Task> tasks;
const string FILE_NAME = "tasks.txt";
int nextId = 1;

// Save tasks to file
void saveTasks()
{
    ofstream file(FILE_NAME);

    if (!file)
    {
        cout << "\nError saving file!\n";
        return;
    }

    for (const auto &task : tasks)
    {
        file << task.id << "|"
             << task.title << "|"
             << task.completed << endl;
    }

    file.close();
}

// Load tasks from file
void loadTasks()
{
    ifstream file(FILE_NAME);

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        Task task;
        string status;

        getline(ss, line, '|');
        task.id = stoi(line);

        getline(ss, task.title, '|');

        getline(ss, status);
        task.completed = (status == "1");

        tasks.push_back(task);

        if (task.id >= nextId)
            nextId = task.id + 1;
    }

    file.close();
}

// Add Task
void addTask()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Task task;

    task.id = nextId++;
    task.completed = false;

    cout << "\nEnter Task Title: ";
    getline(cin, task.title);

    tasks.push_back(task);

    saveTasks();

    cout << "\nTask Added Successfully!\n";
}

// View Tasks
void viewTasks()
{
    if (tasks.empty())
    {
        cout << "\nNo Tasks Available.\n";
        return;
    }

    cout << "\n=========================================\n";
    cout << "              TASK LIST\n";
    cout << "=========================================\n";

    for (const auto &task : tasks)
    {
        cout << "\nTask ID : " << task.id;
        cout << "\nTitle   : " << task.title;
        cout << "\nStatus  : "
             << (task.completed ? "Completed" : "Pending");
        cout << "\n-----------------------------------------";
    }
}

int main()
{
    loadTasks();

    cout << "=========================================\n";
    cout << "      FILE BASED TASK MANAGER\n";
    cout << "=========================================\n";

    cout << "\n1. Add Task";
    cout << "\n2. View Tasks";
    cout << "\n3. Exit";

    int choice;

    do
    {
        cout << "\n\nEnter Choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter again: ";
        }

        switch (choice)
        {
        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            saveTasks();
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}