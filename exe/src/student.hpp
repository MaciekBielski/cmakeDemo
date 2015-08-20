#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

class Student{
public:
    Student(std::string nm, std::string sm);
    void sayHello();
private:
    std::string name,surname;
};
#endif /*LIST_HPP*/
