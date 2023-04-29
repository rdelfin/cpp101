#include <iostream>

int main() {
    int n, num_inputs;
    std::string line;
    std::getline(std::cin, line);
    num_inputs = std::stoi(line);

    for (int i=0; i< num_inputs; i++) {
        std::getline(std::cin, line);
        n = std::stoi(line);
        
        if (n < 1){
            std::cerr << "Please enter a positive integer." << std::endl;
            return 1;
        }
        while ( n != 1 )  {
            std::cout << n << ", ";
            if ( n%2 == 0) {
                n /= 2;
            }else{
                n += 2 * n + 1;
            }
        }
        std::cout << "1" << std::endl;
    }
    return 0;
}
