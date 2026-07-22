#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    string playerName;
    int score = 0;
    int health = 100;
    char playAgain = 'Y';

    cout << "=====================================\n";
    cout << "     TREASURE HUNT ADVENTURE\n";
    cout << "=====================================\n\n";

    cout << "Enter your name: ";
    getline(cin, playerName);

    while (toupper(playAgain) == 'Y')
    {
        cout << "\n---------------------------------\n";
        cout << "Health : " << health << endl;
        cout << "Score  : " << score << endl;
        cout << "---------------------------------\n";

        cout << "\nChoose a path:\n";
        cout << "1. Dark Forest\n";
        cout << "2. Mysterious Cave\n";
        cout << "3. Ancient Temple\n";
        cout << "Enter your choice: ";

        int path;
        cin >> path;

        if (path < 1 || path > 3)
        {
            cout << "\nInvalid choice!\n";
            continue;
        }

        int event = rand() % 3;

        cout << "\nExploring...\n\n";

        switch (event)
        {
        case 0:
            cout << "🎁 You found hidden treasure!\n";
            score += 50;
            break;

        case 1:
            cout << "👹 A monster attacked you!\n";
            health -= 20;
            score += 20;
            break;

        case 2:
            cout << "💎 You discovered a magical crystal!\n";
            score += 30;
            health += 10;

            if (health > 100)
                health = 100;

            break;
        }

        cout << "\nCurrent Health : " << health << endl;
        cout << "Current Score  : " << score << endl;

        if (health <= 0)
        {
            cout << "\nGame Over!\n";
            break;
        }

        cout << "\nDo you want to continue? (Y/N): ";
        cin >> playAgain;
    }

    cout << "\n=====================================\n";
    cout << "Thanks for playing, " << playerName << "!\n";
    cout << "Final Score : " << score << endl;
    cout << "Final Health: " << health << endl;
    cout << "=====================================\n";

    return 0;
}