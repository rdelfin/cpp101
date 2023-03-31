#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

unsigned long read_ulong_cin();
float read_float_cin();
std::string read_string_cin();

// As taken from 03_organise/classes2.cpp
class Person {
   public:
    Person(std::string first_name, std::string last_name, unsigned long age)
        : first_name_(first_name), last_name_(last_name), age_(age) {}

    // A default constructor is necessary so C++ can initialise people when it
    // creates an array
    Person() : first_name_(""), last_name_(""), age_(0) {}

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

int main(int argc, char* argv[]) {
    std::cout << "How many people do you want to add? " << std::flush;
    size_t num_people = read_ulong_cin();

    std::cout << "Creating array for " << num_people << " people" << std::endl;
    Person* people = new Person[num_people];

    // Go through each person and get their information
    for (size_t i = 0; i < num_people; i++) {
        std::cout << "Person #" << (i + 1) << std::endl;

        // Get individual fields
        std::cout << "\tWhat's their first name? " << std::flush;
        std::string first_name = read_string_cin();
        std::cout << "\tWhat's their last name? " << std::flush;
        std::string last_name = read_string_cin();
        std::cout << "\tWhat's their age? " << std::flush;
        unsigned long age = read_ulong_cin();

        // Update element in array with new information
        people[i] = Person(first_name, last_name, age);
    }

    std::cout << std::endl << "Printing people information" << std::endl;
    // You can use pointers same way you would use iterators
    for (auto person_it = people; person_it < people + num_people;
         person_it++) {
        person_it->print();
    }

    // Always, ALWAYS delete objects you allocate with new when you're done with
    // them!
    delete[] people;
}

unsigned long read_ulong_cin() {
    std::string line;
    std::getline(std::cin, line);
    return std::stoul(line);
}

float read_float_cin() {
    std::string line;
    std::getline(std::cin, line);
    return std::stof(line);
}

std::string read_string_cin() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}
