#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::cout << "You've passed " << argc << " arguments" << std::endl;
    std::cout << "The arguments are:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    std::vector<int> myvec{0, 2, 3};
    std::vector<int> myvec2(10, 0);
    // std::vector<float> myvec;
    // for (int i = 0; i < 10; i++) {
        // myvec.push_back(i);
    // }

    for (int i : myvec) {
        std::cout << i << std::endl;
    }
    for (int i : myvec2) {
        std::cout << i << std::endl;
    }
}
