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

    if (Collatz_state == 0)
    {
        std::cout << "0 is not accepted, give me a better number:" << std::flush;
        std::getline(std::cin, line);
        unsigned int Collatz_state = std::stoi(line);
    } /*this is a bit crap because it only checks once, if the user puts again 0, then it does not catch it,
    but i do not know how to raise errors in c++ yet, maybe that would have been better? */

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