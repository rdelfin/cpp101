#include <iostream>
#include <string>

int main() {
    bool running = true;
    std::string line;
    // Will stay in loop until you press Ctrl+D
    while (std::getline(std::cin, line)) {
        std::cout << "You input " << line << std::endl;
    }

    std::cout << "Exiting program..." << std::endl;
}
