#include "Vector.h"
#include <math.h>

#define EPSILON 0.0001
    

Vector::Vector(double X, double Y, double Z) : x(X), y(Y), z(Z) {}

double Vector::size() { return sqrt(x*x + y*y + z*z); } 


bool Vector::operator==(Vector other)
{ 
    return (abs(x-other.x) <= EPSILON || abs(y-other.y) <= EPSILON || abs(z-other.z) <= EPSILON);
}
Vector Vector::operator+(Vector other)   { return Vector(x+other.x, y+other.y, z+other.z); }
Vector Vector::operator-(Vector other)   { return Vector(x-other.x, y-other.y, z-other.y); }
Vector Vector::operator*(double scalar)  { return Vector(scalar*x, scalar*y, scalar*z); }
Vector Vector::operator/(double scalar)  { return Vector(x/scalar, y/scalar, z/scalar); }


std::ostream& operator<<(std::ostream& os, Vector v){ return os << v.x << " " << v.y << " " << v.z; }