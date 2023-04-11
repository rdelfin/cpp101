#pragma once

#include <string>
#include <iostream>
#include <array>


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

   public:
    std::string first_name_;
    std::string last_name_;
    unsigned long age_;
};

class OutOfBoundsException : public std::exception {
   public:
    std::string what() { return "Index out of bounds"; }
};
 
class PersonVector {
   public:
    // This constructor expects you to create an array that contains `size`
    // elements, all containing the value `initial_value`
    PersonVector(size_t size, Person initial_value) {
        size_ = size;
        people_ = new Person[size_];
        for(int i=0; i<(int)size; i++){
            people_[i].first_name_ = initial_value.first_name_;
            people_[i].last_name_ = initial_value.last_name_;
            people_[i].age_ = initial_value.age_;
        }
    }

    ~PersonVector() {
        // Put your code here
        //delete[] people_ ;
    }

    // This function should return a reference to the person at the index
    // provided
    // Notice we expect that if we request an index that's not in the vector,
    // you will *throw* an OutOfBoundsException. If you don't know how to do
    // that, please read the README file
    Person& get(size_t index) {
        // Put your code here
        //if((index > (size_t) size_) || ((int)index == 0)){
        if( ((int)size_ == 0 ) || (index > size_)){
            throw OutOfBoundsException();
        }
        return people_[index]; 
    }

    // This function should return the number of elements in the vector
    size_t size() {
        return size_;
    }

    // This will insert a new person at the end of the array. This will require
    // the array to become larger. How would you achieve that with the tools
    // you've learned?
    void push_back(const Person& person) {
        // Put your code here
        int new_size = size_ + 1;
        Person* temp_ = new Person[new_size];

        // Create temporary memory
        for(int i=0; i<(int)size_; i++){
            temp_[i].first_name_ = people_[i].first_name_;
            temp_[i].last_name_ = people_[i].last_name_;
            temp_[i].age_ = people_[i].age_;
        }

        // Add the latest Person
        temp_[new_size - 1].first_name_ = person.first_name_;
        temp_[new_size - 1].last_name_ = person.last_name_;
        temp_[new_size - 1].age_ = person.age_;

        // Delete existing memory
        delete[] people_ ;

        people_ = temp_;

        // Modify size of internal memory
        size_ = new_size;

    }

    // This will remove the last person from the end of the array. This *might*
    // require you to resize the array (open question: how do you avoid a resize
    // and make all other methods still work?).
    // If there is no last element, you should do nothing.
    void remove_back() {
        // Put your code here
        int new_size = size_ - 1;
        Person* temp_ = new Person[new_size];

        // Create temporary memory
        for(int i=0; i<(int)new_size; i++){
            temp_[i].first_name_ = people_[i].first_name_;
            temp_[i].last_name_ = people_[i].last_name_;
            temp_[i].age_ = people_[i].age_;
        }

        // Delete existing memory
        delete[] people_ ;

        people_ = temp_;

        // Modify size of internal memory
        size_ = new_size;
    }

    // This will replace the person at the given index with the provided person.
    // Notice it's a const reference (a reference that can't be modified
    void replace(size_t index, const Person& person) {
        // Put your code here
        people_[index] = person;
    }

    // This function returns true if the vector contains the given person (i.e.
    // that there's a person in the vector that is equal to the one passed in)
    // and false otherwise. The way we define whether two people are "equal" is
    // if all the fields are also equal. Note that, thanks to a function we
    // implemented as part of the homework, this is the behaviour you will get
    // if you compare two People objects with a `==` operator
    bool contains(const Person& person) {
       for(int i=0; i<(int)size_; i++){
            if((people_[i].first_name_ == person.first_name_) && 
            (people_[i].last_name_ == person.last_name_) &&
            (people_[i].age_ == person.age_)){
                return true;
            }
       }
        return false;
    }

   public:
    // Feel free to add any useful properties/member variables here.
    size_t size_;
    Person* people_;

    
    
};
