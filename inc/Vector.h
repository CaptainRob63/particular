#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
    double x,y,z;

    Vector(double X = 0, double Y = 0, double Z = 0);
    
    double size();

    Vector operator+(Vector);
    Vector operator-(Vector);
};

#endif // VECTOR_H