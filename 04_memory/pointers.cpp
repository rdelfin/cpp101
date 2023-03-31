#include <iostream>

int main() {
    std::string some_word = "foot";
    std::string* some_word_ptr = &some_word;

    (*some_word_ptr).append("ball");

    // Prints "football"
    std::cout << "Output after first append:" << std::endl;
    std::cout << "\t" << some_word << std::endl;
    std::cout << "\t" << *some_word_ptr << std::endl;

    // Equivalent to the call above
    some_word_ptr->append("s");

    // Prints "footballs"
    std::cout << "Output after second append:" << std::endl;
    std::cout << "\t" << some_word << std::endl;
    std::cout << "\t" << some_word << std::endl;
    std::cout << "\t" << *some_word_ptr << std::endl;

    // Prints a memory address
    std::cout << "Memory address:" << std::endl;
    std::cout << "\t" << some_word_ptr << std::endl;
}
