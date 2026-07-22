#include <iostream>
using namespace std;

void halfPyramid(int n)
{
    cout << "\nHalf Pyramid\n\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}

void invertedPyramid(int n)
{
    cout << "\nInverted Half Pyramid\n\n";
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}

void fullPyramid(int n)
{
    cout << "\nFull Number Pyramid\n\n";

    for (int i = 1; i <= n; i++)
    {
        for (int s = 1; s <= n - i; s++)
            cout << "  ";

        for (int j = 1; j <= i; j++)
            cout << j << " ";

        cout << endl;
    }
}

void floydTriangle(int n)
{
    cout << "\nFloyd's Triangle\n\n";

    int num = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice, rows;

    do
    {
        cout << "\n=====================================\n";
        cout << "     NUMBER PATTERN GENERATOR\n";
        cout << "=====================================\n";

        cout << "\n1. Half Pyramid\n";
        cout << "2. Inverted Half Pyramid\n";
        cout << "3. Full Number Pyramid\n";
        cout << "4. Floyd's Triangle\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 5)
        {
            cout << "\nThank you!\n";
            break;
        }

        if (choice < 1 || choice > 5)
        {
            cout << "\nInvalid choice!\n";
            continue;
        }

        cout << "Enter number of rows: ";
        cin >> rows;

        if (rows <= 0)
        {
            cout << "\nRows must be greater than 0.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            halfPyramid(rows);
            break;

        case 2:
            invertedPyramid(rows);
            break;

        case 3:
            fullPyramid(rows);
            break;

        case 4:
            floydTriangle(rows);
            break;
        }

    } while (true);

    return 0;
}