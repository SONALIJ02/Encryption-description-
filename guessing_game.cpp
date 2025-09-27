// Wailinn Saw
// Guessing Game with Reverse Guessing Game
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <string>

using namespace std;

// Function prototype for reverse guessing game
void ReverseGuessingGame();

int main() {
    srand(static_cast<unsigned int>(time(NULL))); // Seed random once

    string name;
    char no, again;
    int choice;

    cout << "What is your name? ";
    getline(cin, name);

    // Validate name
    while (true) {
        cout << "\nIs your name: " << name << " ? (y/n): ";
        cin >> no;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (no == 'y' || no == 'Y') break;
        else if (no == 'n' || no == 'N') {
            cout << "Enter your name: ";
            getline(cin, name);
        }
        else {
            cout << "Please only answer y or n.\n";
        }
    }

    while (true) {
        system("cls"); // Windows only, use "clear" for Linux/Mac
        cout << "\tWelcome to the Guessing Game, " << name << "!\n";
        cout << "\nPlease select one from the menu:\n";
        cout << "\t1. Guessing Game\n";
        cout << "\t2. Reverse Guessing Game\n";
        cout << "\t3. Exit\n";
        cin >> choice;

        if (choice == 3) {
            cout << "\nThank you for playing, " << name << "! Goodbye.\n";
            break;
        }
        else if (choice == 1) {
            const int num_of_guess = 10;
            int min, max, secretNumber;
            int player_guess[num_of_guess];

            do {
                cout << "Enter minimum value to guess from: ";
                while (!(cin >> min) || min < 0) {
                    cout << "Please enter a valid number >= 0: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Enter maximum value to guess up to: ";
                while (!(cin >> max) || max <= min) {
                    cout << "Enter a number greater than " << min << ": ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                secretNumber = rand() % (max - min + 1) + min;

                cout << "\nI have picked a number between " << min << " and " << max << ". You have 10 tries!\n";

                int total_guess = 0;
                bool guessed = false;

                for (total_guess = 0; total_guess < num_of_guess; total_guess++) {
                    cout << "Try #" << (total_guess + 1) << ": ";
                    while (!(cin >> player_guess[total_guess])) {
                        cout << "Please enter a number: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (player_guess[total_guess] < min || player_guess[total_guess] > max) {
                        cout << "Your guess must be between " << min << " and " << max << ". Try again.\n";
                        total_guess--;
                        continue;
                    }

                    if (player_guess[total_guess] < secretNumber)
                        cout << "Too low!\n";
                    else if (player_guess[total_guess] > secretNumber)
                        cout << "Too high!\n";
                    else {
                        cout << "Congratulations! You guessed the number " << secretNumber
                             << " in " << (total_guess + 1) << " tries.\n";
                        guessed = true;
                        break;
                    }
                }

                if (!guessed) {
                    cout << "Sorry! You've used all 10 tries. The number was " << secretNumber << ".\n";
                }

                cout << "Your guesses: ";
                for (int j = 0; j <= total_guess; j++) {
                    cout << player_guess[j] << " ";
                }
                cout << "\nDo you want to play again? (y/n): ";
                cin >> again;
            } while (again == 'y' || again == 'Y');

        }
        else if (choice == 2) {
            ReverseGuessingGame();
        }
        else {
            cout << "Invalid choice! Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}

// Reverse guessing game: computer guesses your number
void ReverseGuessingGame() {
    int minNum, maxNum, myNumber;
    char again;

    do {
        cout << "Enter minimum value: ";
        while (!(cin >> minNum) || minNum < 0) {
            cout << "Enter a valid number >= 0: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter maximum value: ";
        while (!(cin >> maxNum) || maxNum <= minNum) {
            cout << "Enter a number greater than " << minNum << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Pick a number between " << minNum << " and " << maxNum << ": ";
        while (!(cin >> myNumber) || myNumber < minNum || myNumber > maxNum) {
            cout << "Enter a valid number between " << minNum << " and " << maxNum << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int minGuess = minNum, maxGuess = maxNum;
        int computerguess;
        int tries = 0;
        const int max_allowed_guesses = 10;
        bool guessed = false;

        while (tries < max_allowed_guesses) {
            computerguess = rand() % (maxGuess - minGuess + 1) + minGuess;
            tries++;
            cout << "Computer guesses: " << computerguess << "\n";

            if (computerguess == myNumber) {
                cout << "Computer guessed your number in " << tries << " tries!\n";
                guessed = true;
                break;
            }

            char feedback;
            cout << "Is it too high (h) or too low (l)? ";
            cin >> feedback;

            if (feedback == 'h' || feedback == 'H')
                maxGuess = computerguess - 1;
            else if (feedback == 'l' || feedback == 'L')
                minGuess = computerguess + 1;
            else
                cout << "Invalid input, assuming guess was incorrect.\n";
        }

        if (!guessed)
            cout << "Computer couldn't guess your number within " << max_allowed_guesses << " tries.\n";

        cout << "Do you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
}
