#include <iostream>

int main() {
    // Ask for a number
    int32_t number;
    std::cin >> number;
    std::cout << std::endl;

    // Make sure that the number is positive
    if ( number <= 0){
        return -1;
    }

    // Start printing all the steps
    std::cout << number << std::endl;

    while (number!=1){
        if (number%2 == 0){
            number = number/2;
            std::cout << number << std::endl;
        }
        else {
            number = (3 * number) + 1;
            std::cout << number << std::endl;
        }
    }

    return 0;
}
