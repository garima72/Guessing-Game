
#include <iostream>
#include <cstdlib>
#include <ctime>

class GuessingGame {
private:
    int targetNumber;
    int attempts;

public:

    GuessingGame() {
        targetNumber = std::rand() % 100 + 1;
        attempts = 0;
    }

    // Encapsulation
    void incrementAttempts() {
        attempts++;
    }

    int getAttempts() const {
        return attempts;
    }

    bool checkGuess(int guess) const {
        if (guess > targetNumber) {
            std::cout << "Too High! Try again.\n";
            return false;
        } else if (guess < targetNumber) {
            std::cout << "Too Low! Try again.\n";
            return false;
        } else {
            std::cout << "Correct! You guessed it in " << attempts << " attempts!\n";
            return true;
        }
    }
};

int main() {
    char choice;
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "========================================\n";
    std::cout << "   Welcome to Number Guessing Game!   \n";
    std::cout << "========================================\n";
    std::cout << "Guess a number between 1 and 100\n\n";

    do {
        GuessingGame gameInstance;
        int guess = 0;
        bool isCorrect = false;

        std::cout << "A new number has been generated!\n";

        do {
            std::cout << "\nEnter your guess: ";

            // Input Validation Loop
            while (!(std::cin >> guess)) {
                std::cout << "Invalid input! Please enter a number only: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

            if (guess < 1 || guess > 100) {
                std::cout << "Please enter a number between 1 and 100!\n";
                continue;
            }

            gameInstance.incrementAttempts();
            isCorrect = gameInstance.checkGuess(guess);

        } while (!isCorrect);

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

    } while (choice == 'y' || choice == 'Y');

    std::cout << "\nThanks for playing! Goodbye!\n";
    std::cout << "========================================\n";

    return 0;
}