#include <iostream>
#include <string>

using namespace std;

bool guessed_numbers(int *expected, int *actual)
{

    cout << "Your guess are the following numbers " << expected[0] << " "
         << expected[1] << " " << expected[2] << endl;

    cout << "The actual numbers were " << actual[0] << " "
         << actual[1] << " " << actual[2] << endl;

    for (size_t i = 0; i < 3; i++)
    {
        bool found = false;
        for (size_t j = 0; j < 3; j++)
        {
            cout << "TEST EXPECTED ACTUAL" << " " << expected[i] << " == " << actual[j] << endl;
            if (expected[i] == actual[j] && expected[i] != INT_MIN && !found) // check if same values and not null
            {
                expected[i] = INT_MIN;
                actual[j] = INT_MIN;
                found = true;
            }
            
        }
    }

    for (size_t i = 0; i < (sizeof(expected) / sizeof(*expected)); i++)
    {
        cout << "TESTTTT " << expected[0] << " "
         << expected[1] << " " << expected[2] << endl;

        if (expected[i] != INT_MIN)
        {
            cout << "You have guess wrong and now you died...";
            return true;
        }
        
    }
    

    return false;
}

bool game_turn()
{
    string string;

    int number1 = 3;
    int number2 = 3;
    int number3 = 3;
    int sum = number1 + number2 + number3;
    long mul = number1 * number2 * number3;

    cout << "the three numebrs together are summed up to " << sum << " and multiplied to " << mul << endl;
    cout << "Guess the numbers, write them with spaces and with x in the end" << endl;
    cin >> string;

    int guessed1, guessed2, guessed3;
    guessed1 = stoi(string.substr(0, string.find(" ")));
    guessed2 = stoi(string.substr(0, string.find(" ")));
    guessed3 = stoi(string.substr(0, string.find(" ")));

    // cout << "Your guess are the following numbers " << guessed1 << " "
    // << guessed2 << " " << guessed3 << endl;

    int expected[3] = {number1, number2, number3};
    int actual[3] = {guessed1, guessed2, guessed3};

    return guessed_numbers(expected, actual);
}

int main()
{

    const char *ime = "Miha Stele";
    cout << "Hello"
         << " " << ime;
    cout << endl
         << endl
         << endl;

    // Simple game
    short turn = 0;
    while (turn < 10)
    {
        if (game_turn())
        {
            return 0;
        }
        ++turn;
    }

    return 0;
}
