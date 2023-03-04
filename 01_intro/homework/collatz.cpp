#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

int main()
{
    std::string line;

    // Get first number
    std::cout << "Give me a number: " << std::flush;
    std::getline(std::cin, line);
    unsigned int Collatz_state = std::stoi(line);

    // std::cout << "Collatz Base is " << Collatz_state << std::endl;

    while (Collatz_state != 1)
    {
        if (Collatz_state % 2 == 0)
        {
            Collatz_state = Collatz_state / 2;
        }
        else
        {
            Collatz_state = Collatz_state * 3 + 1;
        }
        std::cout << Collatz_state << std::endl;
    }

    return 0;
}