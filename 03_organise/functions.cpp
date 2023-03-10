#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "CLI/CLI11.hpp"

// Forward declare all functions up here. Why do we need to do this?
// If we forget this step, you won't be able to call a function before you
// define it. This gives the compiler a heads up that this function exists and
// that we'll tell it what it does later.
void print_lines(std::vector<std::pair<std::string, std::string>> lines);
std::vector<std::pair<std::string, std::string>> read_and_parse(
    std::string path);
std::pair<std::string, std::string> parse_line(std::string line);
std::vector<std::string> read_file_lines(std::string path);

int main(int argc, char* argv[]) {
    // Setup CLI
    CLI::App app{"An example CLI tool"};
    std::string file_path;
    app.add_option("-f,--file", file_path, "File to open");
    CLI11_PARSE(app, argc, argv);

    // Fetch the data
    std::vector<std::pair<std::string, std::string>> lines =
        read_and_parse(file_path);
    // Print it to the terminal
    print_lines(lines);
}

void print_lines(std::vector<std::pair<std::string, std::string>> lines) {
    std::cout << "Printing file" << std::endl;
    for (std::pair<std::string, std::string> line : lines) {
        std::cout << "\"" << line.first << "\" is paired with \"" << line.second
                  << "\"" << std::endl;
    }
}

std::vector<std::pair<std::string, std::string>> read_and_parse(
    std::string path) {
    // First, read in all lines in the file
    std::vector<std::string> lines = read_file_lines(path);

    std::vector<std::pair<std::string, std::string>> result;

    // Next, for each line parse it and add it to the result
    for (std::string line : lines) {
        result.push_back(parse_line(line));
    }

    // Finally return
    return result;
}

std::pair<std::string, std::string> parse_line(std::string line) {
    size_t comma_position = line.find(",");
    // Returns two substrings. One before the comma, one after
    return std::pair(line.substr(0, comma_position),
                     line.substr(comma_position + 1));
}

std::vector<std::string> read_file_lines(std::string path) {
    // Special class for reading in from a file
    std::ifstream file(path);

    std::vector<std::string> lines;
    std::string line;

    // Read in one line from the file at a time
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    // Return the contents
    return lines;
}
