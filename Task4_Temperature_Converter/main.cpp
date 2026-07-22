#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void menu()
{
    cout << "\n====================================\n";
    cout << "      TEMPERATURE CONVERTER\n";
    cout << "====================================\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "3. Celsius to Kelvin\n";
    cout << "4. Kelvin to Celsius\n";
    cout << "5. Fahrenheit to Kelvin\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "7. Exit\n";
}

int main()
{
    int choice;
    double temp;

    do
    {
        menu();

        cout << "\nEnter your choice: ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number: ";
        }

        if (choice == 7)
        {
            cout << "\nThank you for using the Temperature Converter!\n";
            break;
        }

        if (choice < 1 || choice > 7)
        {
            cout << "\nInvalid choice!\n";
            continue;
        }

        cout << "Enter temperature: ";
        while (!(cin >> temp))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a valid temperature: ";
        }

        cout << fixed << setprecision(2);

        switch (choice)
        {
        case 1:
            cout << "Result: " << (temp * 9 / 5) + 32 << " °F\n";
            break;

        case 2:
            cout << "Result: " << (temp - 32) * 5 / 9 << " °C\n";
            break;

        case 3:
            cout << "Result: " << temp + 273.15 << " K\n";
            break;

        case 4:
            cout << "Result: " << temp - 273.15 << " °C\n";
            break;

        case 5:
            cout << "Result: " << ((temp - 32) * 5 / 9) + 273.15 << " K\n";
            break;

        case 6:
            cout << "Result: " << ((temp - 273.15) * 9 / 5) + 32 << " °F\n";
            break;
        }

    } while (true);

    return 0;
}