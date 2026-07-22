#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>

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


bool compareTask(Task a, Task b)
{
    return a.id < b.id;
}

void sortTasks()
{
    sort(tasks.begin(), tasks.end(), compareTask);

    saveTasks();

    cout << "\nTasks Sorted Successfully!\n";
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


void updateTask()
{
    int id;
    cout << "\nEnter Task ID to update: ";
    cin >> id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto &task : tasks)
    {
        if (task.id == id)
        {
            cout << "Enter New Task Title: ";
            getline(cin, task.title);

            saveTasks();

            cout << "\nTask Updated Successfully!\n";
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}



void deleteTask()
{
    int id;

    cout << "\nEnter Task ID to delete: ";
    cin >> id;

    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].id == id)
        {
            tasks.erase(tasks.begin() + i);

            saveTasks();

            cout << "\nTask Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}


void searchTask()
{
    int id;

    cout << "\nEnter Task ID to search: ";
    cin >> id;

    for (const auto &task : tasks)
    {
        if (task.id == id)
        {
            cout << "\n========== TASK FOUND ==========\n";
            cout << "ID      : " << task.id << endl;
            cout << "Title   : " << task.title << endl;
            cout << "Status  : "
                 << (task.completed ? "Completed" : "Pending")
                 << endl;
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}


void markCompleted()
{
    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;

    for (auto &task : tasks)
    {
        if (task.id == id)
        {
            if (task.completed)
            {
                cout << "\nTask is already completed.\n";
                return;
            }

            task.completed = true;

            saveTasks();

            cout << "\nTask Marked as Completed!\n";
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}

void taskStatistics()
{
    int completed = 0;

    for (const auto &task : tasks)
    {
        if (task.completed)
            completed++;
    }

    cout << "\n========== TASK STATISTICS ==========\n";
    cout << "Total Tasks      : " << tasks.size() << endl;
    cout << "Completed Tasks  : " << completed << endl;
    cout << "Pending Tasks    : " << tasks.size() - completed << endl;
}

int main()
{
    loadTasks();

    cout << "\n=====================================\n";
    cout << "     FILE BASED TASK MANAGER\n";
    cout << "=====================================\n";

    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Update Task\n";
    cout << "4. Delete Task\n";
    cout << "5. Search Task\n";
    cout << "6. Mark Completed\n";
    cout << "7. Task Statistics\n";
    cout << "8. Sort Tasks\n";
    cout << "9. Exit\n";

    int choice;

    do{
        cout << "\n\nEnter Choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter again: ";
        }

        switch(choice){
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                updateTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                searchTask();
                break;

            case 6:
                markCompleted();
                break;

            case 7:
                saveTasks();
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }


    int choice;
    do{
        cout << "\nEnter Choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 9){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Choice! Enter Again: ";
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
                updateTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                searchTask();
                break;

            case 6:
                markCompleted();
                break;

            case 7:
                taskStatistics();
                break;

            case 8:
                sortTasks();
                break;

            case 9:
                saveTasks();
                cout << "\nThank You for using File Based Task Manager!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }            



    } while (!(cin >> choice) || choice < 1 || choice > 9){

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Choice! Enter again: ";
    }

    return 0;
}