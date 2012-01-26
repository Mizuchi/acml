#include"../include/acml/json.hpp"
#include<iostream>

struct Person {
    std::string name;
    double height;
    int weight;
    Person(std::string n, double h, int w):
        name(n), height(h), weight(w) {}
};

// ACML_REGISTER must in the global scope
// ACML_REGISTER(
//    ClassName, 
//    (BaseClassName1)(BaseClassName2)... ,
//    (MemberName1)(MemberName2)...
//    )

ACML_REGISTER(Person, , (name)(height)(weight))

int main() {
    Person noumi("Kudryavka Anatolyevna Strugatskaya", 1.45, 39);
    std::cout << acml::json::dumps(noumi) << std::endl;
}
