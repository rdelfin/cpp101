#include <iostream>

int main() {
    int num;
    std::string line;
    std::cout << "Give me a number: " << std::endl;
    std::getline(std::cin, line);

    try {
        num = std::stod(line);
    } catch (std::exception) {
        return 1;
    }
    if (num <= 0) return 1;
    std::cout << num << std::endl;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        std::cout << num << std::endl;
    }
    return 0;
}
