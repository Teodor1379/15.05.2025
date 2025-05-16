#ifndef _VECTOR_HEADER_INCLUDED_
#define _VECTOR_HEADER_INCLUDED_



#include <fstream>
#include <iostream>

#include <exception>
#include <stdexcept>



class Vector {
private:
    static unsigned int STEP;



public:
    Vector  (                       );
    Vector  (const Vector& instance );

    ~Vector () noexcept;



public:
    Vector& operator=(const Vector&);



public:
    unsigned int getSize()      const   { return this->size     ;   }
    unsigned int getCapacity()  const   { return this->capacity ;   }



public:
    // Операторът [] и операторът () задължително трябва да са вътрешни методи за класа.

    inline         int& operator[](unsigned int index)         { return this->elements[index]; }
    inline const   int& operator[](unsigned int index) const   { return this->elements[index]; } 

    inline         int& at(unsigned int index)         { if (index >= size) { throw std::out_of_range(""); } return this->elements[index]; }
    inline const   int& at(unsigned int index) const   { if (index >= size) { throw std::out_of_range(""); } return this->elements[index]; }

    int operator()() const noexcept;

    // Ще имплементирам метода за кръгли скоби така че
    // винаги да се връща сумата от елементите на масива.



public:
    friend std::ostream& operator<<(std::ostream&, const Vector&);



public:
    Vector& operator+=(const Vector&);
    Vector& operator-=(const Vector&);
    Vector& operator*=(const Vector&);


    // Предефинирам операторите, които нямат присвояване, като
    // използвам онези оператори, които вече имат присвояване.

    inline Vector operator+(const Vector& instance) const { Vector current = *this; current += instance; return current; }
    inline Vector operator-(const Vector& instance) const { Vector current = *this; current -= instance; return current; }
    inline Vector operator*(const Vector& instance) const { Vector current = *this; current *= instance; return current; }


    Vector& operator++() noexcept;  // ++number
    Vector& operator--() noexcept;  // --number

    Vector operator++(int) noexcept;    // number++
    Vector operator--(int) noexcept;    // number--



    Vector& operator++() { 
        for (unsigned int i = 0; i < this->size; ++i) {
            this->elements[i] += 1;
        }

        return *this;
    }

    Vector operator++(int) {
        Vector current = *this;
        ++(*this);
        return current;
    }


public:
    void pushBack(int element   );
    void  popBack(              );



private:
    int*   allocateMemory(const Vector& );
    void deallocateMemory(              );

    void resize();


private:
    unsigned int    size    ;
    unsigned int    capacity;
    int*            elements;
};



std::ostream& operator<<(std::ostream& stream, const Vector& vector) {
    for (unsigned int i = 0; i < vector.getSize(); ++i) {
        stream << vector[i] << ' ';
    }

    stream << '\n';

    return stream;
}



// <=> is in C++20, we do not want to overload it!

bool operator< (const Vector& vector1, const Vector& vector2);
bool operator> (const Vector& vector1, const Vector& vector2);

bool operator==(const Vector& vector1, const Vector& vector2);
bool operator!=(const Vector& vector1, const Vector& vector2);

bool operator<=(const Vector& vector1, const Vector& vector2);
bool operator>=(const Vector& vector1, const Vector& vector2);



#endif
