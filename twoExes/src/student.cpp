#include "student.hpp"

Student::Student(std::string nm, std::string sm): name(nm), surname(sm){};
void Student::sayHello(){ std::cout<<"Hi, here is: "<<name<<" "<<surname<<std::endl; }

//int main(){
//    Student x("foo","bar");
//    x.sayHello();
//    return 0;
//}
