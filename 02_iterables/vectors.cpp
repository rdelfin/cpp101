#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::vector<float> numbers;
    // Get numbers in a loop
    while (std::getline(std::cin, line)) {
        numbers.push_back(std::stof(line));
    }

    // Compute sum of numbers
    float sum = 0;
    for (float n : numbers) {
        sum += n;
    }
    float average = sum / (float)numbers.size();

    // Compute standard deviation (Formula: sqrt(sum(n - average) / N)
    float square_diff_sum = 0;
    for (float n : numbers) {
        square_diff_sum += std::pow(n - average, 2);
    }
    float standard_deviation =
        std::sqrt(square_diff_sum / (float)numbers.size());

    // Print statistics
    std::cout << "Average: " << average << std::endl;
    std::cout << "Standard Deviation: " << standard_deviation << std::endl;
}
