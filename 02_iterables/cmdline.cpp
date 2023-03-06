#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "You've passed " << argc << " arguments" << std::endl;
    std::cout << "The arguments are:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
}
