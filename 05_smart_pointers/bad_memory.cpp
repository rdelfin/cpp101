#include <iostream>
#include <string>

class Person {
   public:
    Person(const std::string& name) : name(name) {}
    std::string name;
};

// Uncomment both commented lines and look at the change of behaviour
int main() {
    Person* p = new Person("John Doe");
    delete p;
    // Person* p2 = new Person("Apple Appleton");
    std::cout << "Name: " << p->name << std::endl;
    // std::cout << "Name 2: " << p2->name << std::endl;
}
