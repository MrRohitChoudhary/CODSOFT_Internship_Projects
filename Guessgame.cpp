#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); 
    int randomNumber = rand() % 100 + 1; 
    int guess;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
        }
    } while (guess != randomNumber);

    return 0;
}

