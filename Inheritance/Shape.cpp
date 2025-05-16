#include "Shape.hpp"


#include <iostream>



Shape::Shape() {
    // Една стратегия е да задавам стойностите да са nullptr.
    // Друга стратегия е да задавам стойностите да са "".
    // Кое от двте да избера - зависи какво искам да постигна?

    this->name = nullptr;
    this->type = nullptr;

    // setName("");
    // setType("");
}

Shape::Shape(const char* name, const char* type) : name(nullptr), type(nullptr) {
    /* Scenario 1
        setName(name);

        try {
            setType(type);
        } catch (std::bad_alloc& exception) {
            // Тук имаме заделено име,
            // но нямаме заделен тип.

            delete[] this->name;

            throw exception;
        } catch (std::invalid_argument& exception) {
            delete[] this->name;

            throw exception;
        }
    */

    // Scenario 2

    setName(name);

    try {
        setType(type);
    } catch (...) {
        // Тук имаме заделено име,
        // но нямаме заделен тип.

        delete[] this->name;

        throw;
    }
}

Shape::Shape(const Shape& instance) : name(nullptr), type(nullptr) {
    // Не правим това тук!
    // delete[] this->name;
    // delete[] this->type;

    setName(instance.name);

    try {
        setType(instance.type);
    } catch (...) {
        delete[] this->name;

        // this->name = nullptr;

        throw;
    }
}

Shape::Shape(Shape&& instance) noexcept {
    this->name = instance.name;
    this->type = instance.type;

    instance.name = nullptr;
    instance.type = nullptr;

    // this->name = std::exchange(instance.name, nullptr)   C++14
    // this->type = std::exchange(instance.type, nullptr)   C++14
}

Shape::~Shape() {
    delete[] this->name;
    delete[] this->type;

    this->name = nullptr;
    this->type = nullptr;
}



Shape& Shape::operator=(const Shape& instance) {
    if (this != &instance) {
        char* buffer1 = new char[strlen(instance.name) + 1];
        char* buffer2 = nullptr;

        try {
            buffer2 = new char[strlen(instance.type) + 1];
        } catch (std::bad_alloc& exception) {
            delete[] buffer1;

            throw exception;
        }

        strcpy(buffer1, instance.name);
        strcpy(buffer2, instance.type);

        delete[] this->name;
        delete[] this->type;

        this->name = buffer1;
        this->type = buffer2;
    }

    return *this;
}

Shape& Shape::operator=(Shape&& instance) noexcept {
    if (this != &instance) {
        delete[] this->name;
        delete[] this->type;

        this->name = instance.name;
        this->type = instance.type;

        instance.name = nullptr;
        instance.type = nullptr;
    }

    return *this;
}



void Shape::setName(const char* name) {
    if (!Utility::isValid(name) || (this->name != nullptr && strcmp(name, this->name) == 0)) {
        throw std::invalid_argument("Invalid Name Argument!");
    }

    char* temporary = new char[strlen(name) + 1];

    strcpy(temporary, name);

    delete[] this->name;

    this->name = temporary;
}

void Shape::setType(const char* type) {
    if (!Utility::isValid(type) || (this->type != nullptr && strcmp(type, this->type) == 0)) {
        throw std::invalid_argument("Invalid Type Argument!");
    }

    char* temporary = new char[strlen(type) + 1];

    strcpy(temporary, type);

    delete[] this->type;

    this->type = temporary;
}
