#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

void print_duration(std::chrono::time_point<std::chrono::steady_clock> start,
                    std::chrono::time_point<std::chrono::steady_clock> end);
std::vector<float> gen_rand_array(size_t elems);
float compute_mean_copy(std::vector<float> data);
float compute_mean_reference(std::vector<float>& data);

int main() {
    // First generate the array with random values
    std::cout << "Generating vector of 10'000'000 elements..." << std::endl;
    auto nums = gen_rand_array(10'000'000);

    // First section: compute the mean by copy. This should be the slowest
    {
        std::cout << "Computing mean by copy" << std::endl;
        // Start and end are used to time the operation
        auto start = std::chrono::steady_clock::now();
        compute_mean_copy(nums);
        auto end = std::chrono::steady_clock::now();
        print_duration(start, end);
    }

    // Second section: compute the mean by reference. This should be the fastest
    {
        std::cout << "Computing mean by reference" << std::endl;
        auto start = std::chrono::steady_clock::now();
        compute_mean_reference(nums);
        auto end = std::chrono::steady_clock::now();
        print_duration(start, end);
    }
}

std::vector<float> gen_rand_array(size_t elems) {
    std::random_device rd;
    std::mt19937 gen(rd());
    // Create a normal distribution with a mean of 3 and std dev of 5
    std::normal_distribution<> d(3, 5);

    // Create a vector and pre-allocate enough memory for `elems` elements.
    // This eliminates time spend allocating memory (which can be slow!)
    std::vector<float> result;
    result.reserve(elems);

    for (size_t i = 0; i < elems; i++) {
        result.push_back(d(gen));
    }

    return result;
}

// This function computes a mean, but the vector is passed in by copy. In
// theory, this is the most inneficient way of doing so, as all 10M parameters
// will be copied.
float compute_mean_copy(std::vector<float> data) {
    float mean = 0.0;

    for (auto value : data) {
        mean += value;
    }
    mean /= static_cast<float>(data.size());

    return mean;
}

// This function computes a mean, but the vector is passed in by reference. This
// should be the more efficient way of doing so, as references are relatively
// small (8 bytes).
float compute_mean_reference(std::vector<float>& data) {
    float mean = 0.0;

    for (auto value : data) {
        mean += value;
    }
    mean /= static_cast<float>(data.size());

    return mean;
}

void print_duration(std::chrono::time_point<std::chrono::steady_clock> start,
                    std::chrono::time_point<std::chrono::steady_clock> end) {
    std::chrono::duration<double> duration = end - start;
    std::cout << "Action took " << std::fixed << std::setprecision(4)
              << duration.count() << " s" << std::endl;
}
