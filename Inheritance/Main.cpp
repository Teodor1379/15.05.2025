#include <iostream>

#include "Circle.hpp"



int main() {
    Circle c1("Name 1", "Type 1", "Size 1");
    Circle c2("Name 2", "Type 2", "Size 2");

    c2 = c1;

    std::cout << "Hello World!" << std::endl;

    Circle* c3 = new Circle("Name 3", "Type 3", "Size 3");
    Circle* c4 = new Circle("Name 4", "Type 4", "Size 4");

    *c3 = *c4;

    delete c3;
    delete c4;

    // std::cout << Utility::isValid("Name 1") << std::endl;
}
