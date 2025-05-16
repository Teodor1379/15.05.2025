#include "Circle.hpp"



Circle::Circle() : Shape() {
    this->size = nullptr;
}


Circle::Circle(const char* name, const char* type, const char* size) : Shape(name, type) {
    this->size = new char[strlen(size) + 1];

    strcpy(this->size, size);
}

Circle::Circle(const Circle& instance) : Shape(instance) {
    this->size = new char[strlen(instance.size) + 1];

    strcpy(this->size, instance.size);
}


Circle::~Circle() {
    delete[] this->size;
}



Circle& Circle::operator=(const Circle& instance) {
    if (this != &instance) {
        /* 
            Shape::operator=(other);
            char* buffer = new char[strlen(other.size) + 1];
            strcpy(buffer, other.size);
            delete[] this->size;
            this->size = buffer;
        */

        /*
            Try this:

            Shape::operator(instance);

            throw std::exception;
        */

        // Copy And Swap
        // Ще създам копие, което или няма да се създаде,
        // или ще се създаде коректно изцяло. В този смисъл
        // това копие ще е завършено. Тогава ще разменим
        // данните на обекта, изполвайки копието наготово.

        /*
            Circle copyCircle(instance);
            Shape::operator=(std::move(copyCircle));
            std::swap(copyCircle.size, this->size);
        */

        /*
            Circle copyCircle(instance);
            std::swap(*this, copyCircle);
        */

        Circle copyCircle(instance);
        swap(*this, copyCircle);
    }

    return *this;
}
