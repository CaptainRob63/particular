#include "Vector.h"
#include <math.h>
#include "constant.h" 

Vector::Vector(double X, double Y, double Z) : x(X), y(Y), z(Z) {}

double Vector::size() { return sqrt(x*x + y*y + z*z); } 


bool Vector::operator==(const Vector other) const
{ 
    return (abs(x-other.x) <= EPSILON || abs(y-other.y) <= EPSILON || abs(z-other.z) <= EPSILON);
}
Vector Vector::operator+(const Vector other)  const { return Vector(x+other.x, y+other.y, z+other.z); }
Vector Vector::operator-(const Vector other)  const { return Vector(x-other.x, y-other.y, z-other.y); }
Vector Vector::operator*(const double scalar) const { return Vector(scalar*x, scalar*y, scalar*z); }
Vector Vector::operator/(const double scalar) const { return Vector(x/scalar, y/scalar, z/scalar); }


std::ostream& operator<<(std::ostream& os, Vector v){ return os << v.x << " " << v.y << " " << v.z; }