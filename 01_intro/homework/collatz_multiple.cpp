#include <iostream>

int get_num_from_stdin() {
    std::string line;
    int num = -1;

    std::getline(std::cin, line);
    try {
        num = std::stod(line);
    } catch (std::exception) {
        return -1;
    }
    return num;
}


int collatz_len(int num) {
    if (num < 1) return -1;

    int len = 0;
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        len++;
    }
    return len;
}

int main() {
    int num_inputs;
    std::cout << "Give me the data: " << std::endl;

    // Get the number of numbers
    num_inputs = get_num_from_stdin();
    if (num_inputs <= 0) return -1;

    int num;
    int len;
    for (int i = 0; i < num_inputs; i++) {
        num = get_num_from_stdin();
        if (num <= 0) return -1;
        len = collatz_len(num);
        std::cout << len << std::endl;
    }
    return 0;
}
