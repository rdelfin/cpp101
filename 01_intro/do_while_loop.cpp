#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    // Generates a number between 1 and 100 (inclusive)
    int number_to_guess = (rand() % 100) + 1;
    int guessed_number;
    do {
        std::string line;
        std::cout << "Guess my number between 1 and 100: " << std::flush;
        std::getline(std::cin, line);
        guessed_number = std::stoi(line);

        // Give the user a clue (only if they didn't hit the number!)
        if (guessed_number < number_to_guess) {
            std::cout << "Your guess is too low!" << std::endl;
        } else if (guessed_number > number_to_guess) {
            std::cout << "Your guess is too high!" << std::endl;
        }
    } while (number_to_guess != guessed_number);

    std::cout << "Congrats! You guessed my number" << std::endl;
}
