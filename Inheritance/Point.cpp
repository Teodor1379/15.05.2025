#include "Point.hpp"



unsigned int Point::ID = 0;



// Мога да задам стойността на полето currentID в рамките на
// инициализиращия списък. Другият вариант е да задам същата
// стойност в тялото. Когато последното не е възможно? Това
// не е възможно, когато стойността на currentID трябва да е
// const. Тогава единственото място, на което мога да задавам
// стойност на това поле е именно в инициализиращия списък.
// Припомням, че инициализиращия списък се изпълнява ПРЕДИ
// тялото на конструктора. Бъдете внимателни какво правите там.



Point::Point() : currentID(Point::ID++) {
    this->xCoordinate = 0.0;
    this->yCoordinate = 0.0;
    this->zCoordinate = 0.0;

    // this->currentID = Point::ID++;
}



Point::Point(double xCoordinate, double yCoordinate, double zCoordinate) : currentID(Point::ID++) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
    this->zCoordinate = zCoordinate;

    // this->currentID = Point::ID++;
}
