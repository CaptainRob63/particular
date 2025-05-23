#include "Vector.h"
#include <math.h>
    

Vector::Vector(double X, double Y, double Z) : x(X), y(Y), z(Z) {}

double Vector::size() { return sqrt(x*x + y*y + z*z); } 

Vector Vector::operator+(Vector other)   { return Vector(x+other.x, y+other.y, z+other.z); }
Vector Vector::operator-(Vector other)   { return Vector(x-other.x, y-other.y, z-other.y); }
Vector Vector::operator*(double scalar)  { return Vector(scalar*x, scalar*y, scalar*z); }
Vector Vector::operator/(double scalar)  { return Vector(x/scalar, y/scalar, z/scalar); }