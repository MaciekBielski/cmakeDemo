#include "student.hpp"
#include "group.hpp"

int main(){
    Group g;
    g.add(Student("aaa","aaa"));
    g.add(Student("bbb","bbb"));
    g.add(Student("ccc","ccc"));
    g.showAll();
    return 0;
}
