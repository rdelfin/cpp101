#include <iostream>
#include "04_memory/homework/vector.hpp"
#include <vector>


int main(){
    Person p;
    p.first_name_ = "Arvind";
    p.last_name_ = "Pandit";
    p.age_ = 27;
    PersonVector a(3, p);
    std::vector<Person> correct = {p, p, p} ;

    for(int i=0; i<3; i++){
        std::cout << a.get(i).first_name_ << " " << a.get(i).last_name_ << " "  << a.get(i).age_ << std::endl; 
    }

    PersonVector b(0,p);
    std::cout << "size of custom struct is " << (int)b.size_ << std::endl;

    //for(int i=0; i<3; i++){
    //    if(a.get(i+1) == correct[i]){
    //        std::cout << "it is true" << std::endl;
    //    }
    //    else {
    //        std::cout << "it isnt true" << std::endl;
    //    }
    //}
    
    //Person p1("arv", "pan", 19);
    //Person p3();
    //p1.print();
    //Person p2;
    //std::cout << p2.age_ << std::endl;

    PersonVector v(0, Person());
    v.push_back(Person("John", "Smith", 25));
    v.push_back(Person("Mary", "McDonald", 37));

    for(int i=0; i<2; i++){
        std::cout << v.people_[i].first_name_ << " " << v.people_[i].last_name_ << " " << v.people_[i].age_  << std::endl;
    }
    return 0;
}