#include <iostream>

int main() {
    std::string line;
    int x;
    // std::cout << "Hello! Enter a number:" << std::endl;
    
    std::getline(std::cin, line);
    x = std::stof(line);
    if (x <= 0) {
      return 1;
    }

    std::cout << x << std::endl;
    while (x > 1) {
      if (x & 1){
        x = 3*x +1;
      } else {
        x = x / 2;
      }
      std::cout << x << std::endl;
    }

    return 0;
}
