#ifndef _SHAPE_HEADER_INCLUDED_
#define _SHAPE_HEADER_INCLUDED_



#include <exception>
#include <stdexcept>

#include <cstring>

#include "Utility.hpp"



class Shape {
public:
    Shape(                          );
    Shape(const char*, const char*  );
    Shape(const Shape&              );

    ~Shape() noexcept;



public:
    // Какво съм забравил тук?
    // Пропуснал съм оператора за присвояване.

    Shape& operator=(const Shape& instance);
    
    

public:
    // Как да реализираме селекторите на данните?

    inline const char* getName() const noexcept { return this->name; }
    inline const char* getType() const noexcept { return this->type; }

    // Как да реализираме мутатори  на данните?

    void setName(const char*);
    void setType(const char*);



public:
    // Как да създадем Move Semantics?

    Shape(Shape&&)              noexcept;

    Shape& operator=(Shape&&)   noexcept;



public:
    // Бонус: Помним ли какво е Голяма 8-ца?
    // Когато искаме да контролираме адресите...
    // Това не е необходимо за курса и не е
    // нужно да го правите, защото има известни
    // подводни камъни, когато се прави...

    //          Shape* operator&()          { return this;   }
    // const    Shape* operator&() const    { return this;   }



public:
    friend void swap(Shape& shape1, Shape& shape2) {
        std::swap(shape1.name, shape2.name);
        std::swap(shape2.type, shape2.type);
    };



protected:
    char* name;
    char* type;
};



#endif
