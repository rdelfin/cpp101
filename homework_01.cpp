#include <iostream>

int main() {
    std::string line;
    std::cout << "Hello! Enter a positive number: " << std::flush;
    while(std::getline(std::cin, line)) {
        unsigned int n = std::stoi(line);
        unsigned int steps = 0;

        while (n != 1) {
            steps++;
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            std::cout << " " << n;
        }
        std::cout << std::endl;
    }
    return 0;
}