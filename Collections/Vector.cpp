#include "Vector.hpp"



Vector::Vector() {
    this->size      =   0           ;
    this->capacity  =   Vector::STEP;

    this->elements  =   new int[this->capacity];
}

Vector::Vector(const Vector& instance) {
    this->size      =   instance.size                   ;
    this->capacity  =   instance.capacity               ;
    this->elements  =   this->allocateMemory(instance)  ;
}

Vector::~Vector() noexcept {
    delete[] this->elements;
}



Vector& Vector::operator=(const Vector& instance) {
    if (this != &instance) {
        int* buffer = this->allocateMemory(instance);

        delete[] this->elements;

        this->size      =   instance.size       ;
        this->capacity  =   instance.capacity   ;
        this->elements  =   buffer              ;
    }

    return *this;
}



int Vector::operator()() const {
    int sum = 0;

    for (unsigned int i = 0; i < this->size; ++i) {
        sum = sum + this->elements[i];
    }

    return sum;
}



Vector& Vector::operator+=(const Vector& instance) {
    if (this->size == instance.size) {
        for (unsigned int i = 0; i < this->size; ++i) {
            this->elements[i] += instance.elements[i];
        }
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& instance) {
    if (this->size == instance.size) {
        for (unsigned int i = 0; i < this->size; ++i) {
            this->elements[i] -= instance.elements[i];
        }
    }

    return *this;
}

Vector& Vector::operator*=(const Vector& instance) {
    if (this->size == instance.size) {
        for (unsigned int i = 0; i < this->size; ++i) {
            this->elements[i] *= instance.elements[i];
        }
    }

    return *this;
}



Vector& Vector::operator++() noexcept {
    for (unsigned int i = 0; i < this->size; ++i) {
        this->elements[i] += 1;
    }
}

Vector& Vector::operator--() noexcept {
    for (unsigned int i = 0; i < this->size; --i) {
        this->elements[i] -= 1;
    }
}



Vector Vector::operator++(int) noexcept {
    Vector result = *this;
    ++(*this); return result;
}

Vector Vector::operator--(int) noexcept {
    Vector result = *this;
    --(*this); return result;
}



void Vector::pushBack(int element) {
    if (this->size == this->capacity) {
        this->resize();
    }

    this->elements[this->size] = element;

    this->size = this->size + 1;
}

void Vector::popBack() {
    if (this->size == 0) {
        throw std::runtime_error("Min Size Reached!");
    }

    this->size = this->size - 1;
}



int* Vector::allocateMemory(const Vector& instance) {
    int* temporary = new int[instance.capacity];

    try {
        // Тук изключение, тъй като работим с int, няма
        // да се хвърли никога. Работата е там обаче, че
        // ако типът на вектора не беше int, а потенциално
        // тип, който при присвояване потенциално може да
        // хвърли изключение, цикълът трябва да е в try.я

        for (unsigned int i = 0; i < instance.size; ++i) {
            temporary[i] = instance.elements[i];
        }
    } catch (std::exception& exception) {
        delete[] temporary;

        throw exception;
    }

    return temporary;
}

void Vector::deallocateMemory() {
    delete[] this->elements;

    this->elements = nullptr;
}



void Vector::resize() {
    int* buffer = new int[this->capacity * Vector::STEP];

    try {
        for (unsigned int i = 0; i < this->size; ++i) {
            buffer[i] = this->elements[i];
        }
    } catch (std::exception& exception) {
        delete[] buffer;

        throw exception;
    }

    delete[] this->elements;

    this->capacity  =   this->capacity * Vector::STEP   ;
    this->elements  =   buffer                          ;
}



bool operator<(const Vector& vector1, const Vector& vector2) {
    for (unsigned int i = 0; i < std::min(vector1.getSize(), vector2.getSize()); ++i) {
        if (vector1[i] < vector2[i]) { return true;     }
        if (vector1[i] > vector2[i]) { return false;    }
    }

    return vector1.getSize() < vector2.getSize();
}

bool operator>(const Vector& vector1, const Vector& vector2) {
    for (unsigned int i = 0; i < std::min(vector1.getSize(), vector2.getSize()); ++i) {
        if (vector1[i] < vector2[i]) { return false;    }
        if (vector1[i] > vector2[i]) { return true;     }
    }

    return vector1.getSize() > vector2.getSize();
}



bool operator==(const Vector& vector1, const Vector& vector2) {
    if (vector1.getSize() == vector2.getSize()) {
        for (unsigned int i = 0; i < vector1.getSize(); ++i) {
            if (vector1[i] != vector2[i]) {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool operator!=(const Vector& vector1, const Vector& vector2) {
    return !(vector1 == vector2);
}


bool operator<=(const Vector& vector1, const Vector& vector2) {
    return !(vector1 > vector2);
}

bool operator>=(const Vector& vector1, const Vector& vector2) {
    return !(vector1 < vector2);
}
