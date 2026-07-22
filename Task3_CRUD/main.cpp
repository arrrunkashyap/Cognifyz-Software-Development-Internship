#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Task
{
    int id;
    string title;
    bool completed;
};

vector<Task> tasks;
int nextId = 1;

void addTask()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Task task;
    task.id = nextId++;
    task.completed = false;

    cout << "\nEnter Task Title: ";
    getline(cin, task.title);

    tasks.push_back(task);

    cout << "\nTask Added Successfully!\n";
}

void viewTasks()
{
    if (tasks.empty())
    {
        cout << "\nNo Tasks Available.\n";
        return;
    }

    cout << "\n========== TASK LIST ==========\n";

    for (const auto &task : tasks)
    {
        cout << "\nID      : " << task.id;
        cout << "\nTask    : " << task.title;
        cout << "\nStatus  : "
             << (task.completed ? "Completed" : "Pending");
        cout << "\n-------------------------------";
    }
}

void updateTask()
{
    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto &task : tasks)
    {
        if (task.id == id)
        {
            cout << "Enter New Title: ";
            getline(cin, task.title);

            cout << "\nTask Updated Successfully!\n";
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}

void deleteTask()
{
    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;

    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].id == id)
        {
            tasks.erase(tasks.begin() + i);

            cout << "\nTask Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}

void searchTask()
{
    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;

    for (const auto &task : tasks)
    {
        if (task.id == id)
        {
            cout << "\nTask Found\n";
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
            task.completed = true;

            cout << "\nTask Marked as Completed!\n";
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "         TASK MANAGER\n";
        cout << "====================================\n";

        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Update Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Search Task\n";
        cout << "6. Mark Completed\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid Input!\n";
            cout << "Enter Choice: ";

            cin >> choice;
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
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}