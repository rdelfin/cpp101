#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> v;
    std::string line;

    while (std::getline(std::cin, line)) {
        v.push_back(line);
    }

    std::sort(v.begin(), v.end());

    std::cout << "Your sorted output is:" << std::endl;

    for (std::string s : v) {
        std::cout << s << std::endl;
    }
}
