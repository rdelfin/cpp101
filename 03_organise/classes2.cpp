#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "CLI/CLI11.hpp"

// We put the class definition first because it's used below
class Person {
   public:
    Person(std::string first_name, std::string last_name, unsigned long age)
        : first_name_(first_name), last_name_(last_name), age_(age) {}

    void print() {
        std::cout << full_name() << " is " << age_ << " years old."
                  << std::endl;
    }

    std::string full_name() { return first_name_ + " " + last_name_; }

   private:
    std::string first_name_;
    std::string last_name_;
    unsigned long age_;
};

// Forward declare all functions up here. Why do we need to do this?
// If we forget this step, you won't be able to call a function before you
// define it. This gives the compiler a heads up that this function exists and
// that we'll tell it what it does later.
void print_lines(std::vector<Person> people);
std::vector<Person> read_and_parse(std::string path);
Person parse_line(std::string line);
std::vector<std::string> read_file_lines(std::string path);

int main(int argc, char* argv[]) {
    // Setup CLI
    CLI::App app{"An example CLI tool"};
    std::string file_path;
    app.add_option("-f,--file", file_path, "File to open");
    CLI11_PARSE(app, argc, argv);

    // Fetch the data
    std::vector<Person> people = read_and_parse(file_path);
    // Print it to the terminal
    print_lines(people);
}

void print_lines(std::vector<Person> people) {
    std::cout << "Printing file" << std::endl;
    for (Person person : people) {
        person.print();
    }
}

std::vector<Person> read_and_parse(std::string path) {
    // First, read in all lines in the file
    std::vector<std::string> lines = read_file_lines(path);

    std::vector<Person> result;

    // Next, for each line parse it and add it to the result
    for (std::string line : lines) {
        result.push_back(parse_line(line));
    }

    // Finally return
    return result;
}

Person parse_line(std::string line) {
    size_t first_comma_position = line.find(",");
    size_t second_comma_position = line.find(",", first_comma_position + 1);

    // Extract values first
    std::string last_name = line.substr(0, first_comma_position);
    std::string first_name =
        line.substr(first_comma_position + 1,
                    second_comma_position - first_comma_position - 1);
    std::string age_str = line.substr(second_comma_position + 1);
    // Notice how now we store the data directly in this "person" struct
    Person p(first_name, last_name, std::stoul(age_str));
    return p;
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

