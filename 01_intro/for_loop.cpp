#include <iostream>
#include <string>

int main() {
    // Will print every numver between 1 and 100 and say whether
    // they're divisible by 3 or not
    for (unsigned int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            std::cout << i << " is divisible by 3" << std::endl;
        } else {
            std::cout << i << " is not divisible by 3" << std::endl;
        }
    }
}
