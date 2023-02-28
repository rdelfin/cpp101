#include <iostream>
#include <string>
#include <vector>

int main() {
    int i = 10;
    long l = (long)i;    // Converts without issues
    long l2 = long(i);   // Alternative syntax
    float f = (float)i;  // Turns into a fractional number

    float pi = 3.14;
    int j = (int)pi;  // Will convert to 3
    float some_num = 3.99;
    int k = (int)some_num;  // Will also convert to 3

    int my_dollars = 1'000'000;
    // Chars are signed 8-bits, can represent [-128, 127]
    char error_char = (char)my_dollars;  // Will store

    std::cout << "i " << i << std::endl
              << "l " << l << std::endl
              << "l2 " << l2 << std::endl
              << "f " << f << std::endl
              << "pi " << pi << std::endl
              << "j " << j << std::endl
              << "some_num " << some_num << std::endl
              << "k " << k << std::endl
              << "my_dollars " << my_dollars
              << std::endl
              // The "+" here forces the char to be printed as a number (don't
              // ask me why)
              << "error_char " << +error_char << std::endl;
}
