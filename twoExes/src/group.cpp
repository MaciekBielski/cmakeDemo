#include "group.hpp"

void Group::add(Student s){
    list.push_back(s);
};

void Group::showAll(){
    for(Student s: list){
        s.sayHello();
    }
    std::cout<<"cube of 5: "<<pow(5.0,3.0)<<std::endl;
};

