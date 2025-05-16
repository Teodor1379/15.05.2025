#ifndef _POINT_HEADER_INCLUDED_
#define _POINT_HEADER_INCLUDED_



// Искаме да добавим уникален идентификатор на точките.
// Допускаме, че при копиране на точките, също така ще
// се копира и идентификатора на инстанцията на класа.



class Point {
public:
    Point(                      );
    Point(double, double, double);



public:
    double getX()   const   { return this->xCoordinate; }
    double getY()   const   { return this->yCoordinate; }
    double getZ()   const   { return this->zCoordinate; }



private:
    static unsigned int ID; // Static Variable



private:
    double xCoordinate;
    double yCoordinate;
    double zCoordinate;

    const unsigned int currentID; // For the Instance;
};



#endif
