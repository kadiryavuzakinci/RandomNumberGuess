#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

class Game {
private:
    int secretNumber;
    int attemptsLeft;
public:
    Game(int min, int max) {
        // Initialize random seed
        srand(time(0));
        secretNumber = rand() % (max - min + 1) + min; 
        attemptsLeft = 5; 
    }

    bool isGameOver() {
        return attemptsLeft == 0;
    }

    bool checkGuess(int guess) {
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number!" << endl;
            return true;
        }
        else {
            cout << "Incorrect guess. ";
            if (guess < secretNumber) {
                cout << "The number is higher." << endl;
            }
            else {
                cout << "The number is lower." << endl;
            }
            attemptsLeft--;
            cout << "Attempts left: " << attemptsLeft << endl;
            return false;
        }
    }
};

class Player {
private:
    string name;
    int score;
public:
    Player(string playerName) {
        name = playerName;
        score = 0;
    }

    void updateScore(int points) {
        score += points;
    }

    int getScore() {
        return score;
    }

    void resetScore() {
        score = 0;
    }

    void displayScore() {
        cout << "Player: " << name << ", Score: " << score << endl;
    }
};

int main() {
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    Player player(playerName);
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int min, max, difficulty, points = 0;
        cout << "Choose the difficulty level (1-3): ";
        cin >> difficulty;
        switch (difficulty) {
        case 1:
            min = 1;
            max = 50;
            points = 5;
            break;
        case 2:
            min = 1;
            max = 100;
            points = 10;
            break;
        case 3:
            min = 1;
            max = 200;
            points = 20;
            break;
        default:
            cout << "Invalid difficulty level. Defaulting to level 1." << endl;
            min = 1;
            max = 50;
            points = 5;
            break;
        }

        Game game(min, max);
        int guess;
        bool guessedCorrectly = false;

        while (!game.isGameOver()) {
            cout << "Guess the number (between " << min << " and " << max << "): " <<endl;
            cin >> guess;
            if (game.checkGuess(guess)) {
                player.updateScore(points); 
                guessedCorrectly = true;
                break;
            }
        }

        if (!guessedCorrectly) {
            player.resetScore(); 
        }

        player.displayScore();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}