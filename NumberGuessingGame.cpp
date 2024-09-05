#include <iostream>
#include <cstdlib>  
#include <ctime>    
int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int numberToGuess = std::rand() % 100 + 1;
    int userGuess = 0;
    int numberOfTries = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have picked a number between 1 and 100." << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        numberOfTries++;

        if (userGuess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (userGuess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " 
                      << numberOfTries << " tries." << std::endl;
        }
    } while (userGuess != numberToGuess);

    return 0;
}
