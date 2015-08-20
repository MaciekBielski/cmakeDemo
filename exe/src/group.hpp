#ifndef GROUP_HPP
#define GROUP_HPP
#include <iostream>
#include <vector>
#include <math.h>
#include "student.hpp"

class Group{
    public:
        void add(Student s);
        void showAll();
    private:
        std::vector<Student> list;
};
#endif
