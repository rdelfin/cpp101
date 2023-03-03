#include <iostream>

int main() {
    std::string line;

    std::cout << "Enter an integer for n: " << std::flush;
    std::getline(std::cin, line);
    int n = std::stoi(line);
    if (n < 1){
        std::cerr << "Please enter a positive integer." << std::endl;
        return 1;
    }
    while ( n != 1 )  {
        std::cout << n << ",";
        if ( n%2 == 0) {
            n /= 2;
        }else{
            n += 2 * n + 1;
        }
    }
    std::cout << "1" << std::endl;
    return 0;
}
