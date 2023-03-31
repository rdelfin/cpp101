#pragma once

// As taken from 03_organise/classes2.cpp. Don't touch this class
class Person {
   public:
    Person(std::string first_name, std::string last_name, unsigned long age)
        : first_name_(first_name), last_name_(last_name), age_(age) {}

    // A default constructor is necessary so C++ can initialise people when it
    // creates an array
    Person() : first_name_(""), last_name_(""), age_(0) {}

    bool operator==(const Person& rhs) const {
        return first_name_ == rhs.first_name_ && last_name_ == rhs.last_name_ &&
               age_ == rhs.age_;
    }

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

class OutOfBoundsException : public std::exception {
   public:
    char* what() { return "Index out of bounds"; }
};

class PersonVector {
   public:
    // This constructor expects you to create an array that contains `size`
    // elements, all containing the value `initial_value`
    PersonVector(size_t size, Person initial_value) {
        // Put your code here
    }

    ~PersonVector() {
        // Put your code here
    }

    // This function should return a reference to the person at the index
    // provided
    // Notice we expect that if we request an index that's not in the vector,
    // you will *throw* an OutOfBoundsException. If you don't know how to do
    // that, please read the README file
    Person& get(size_t index) {
        // Put your code here
        throw OutOfBoundsException();
    }

    // This function should return the number of elements in the vector
    size_t size() {
        // Put your code here
        return 0;
    }

    // This will insert a new person at the end of the array. This will require
    // the array to become larger. How would you achieve that with the tools
    // you've learned?
    void push_back(const Person& person) {
        // Put your code here
    }

    // This will remove the last person from the end of the array. This *might*
    // require you to resize the array (open question: how do you avoid a resize
    // and make all other methods still work?).
    // If there is no last element, you should do nothing.
    void remove_back() {
        // Put your code here
    }

    // This will replace the person at the given index with the provided person.
    // Notice it's a const reference (a reference that can't be modified
    void replace(size_t index, const Person& person) {
        // Put your code here
    }

    // This function returns true if the vector contains the given person (i.e.
    // that there's a person in the vector that is equal to the one passed in)
    // and false otherwise. The way we define whether two people are "equal" is
    // if all the fields are also equal. Note that, thanks to a function we
    // implemented as part of the homework, this is the behaviour you will get
    // if you compare two People objects with a `==` operator
    bool contains(const Person& person) {
        // Put your code here
        return false;
    }

   private:
    // Feel free to add any useful properties/member variables here.
};
