#include <iostream>
#include <string>

int main() {
    std::string line;

    // Get first number
    std::cout << "Give me a number: " << std::flush;
    std::getline(std::cin, line);
    float a = std::stof(line);
    // Get second number
    std::cout << "Give me another number: " << std::flush;
    std::getline(std::cin, line);
    float b = std::stof(line);
    // Get third number
    std::cout << "Give me yet another number: " << std::flush;
    std::getline(std::cin, line);
    float c = std::stof(line);

    // Print out numbers to user
    std::cout << "You've created a triangle with sides of length " << a << ", "
              << b << ", and " << c << std::endl;

    std::cout << "Testing triangle inequality..." << std::endl;

    // Confirm triagle inequality, no two sides can add up to less than the
    // remaining third
    if ((a + b >= c) && (b + c >= a) && (a + c >= b)) {
        std::cout << "Your triangle is valid!" << std::endl;
    } else {
        std::cout << "Your triangle cannot exist :(" << std::endl;
    }
}
