#ifndef _CIRCLE_HEADER_INCLUDED_
#define _CIRCLE_HEADER_INCLUDED_



#include "Shape.hpp"



class Circle : public Shape {
public:
                Circle(                                         );
    explicit    Circle(const char*, const char*, const char*    ); // We put `explicit` when was 1 parameter...
                Circle(const Circle&                            );

    ~Circle() noexcept;

    

public:
    Circle& operator=(const Circle&);



public:
    const char* getSize() const { return this->size; }



public:
    friend void swap(Circle& circle1, Circle& circle2) noexcept {
        std::swap(static_cast<Shape&>(circle1), static_cast<Shape&>(circle2));
        std::swap(circle1.size, circle2.size);
    }



private:
    char* size;
};



#endif
