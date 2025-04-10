struct Vector {
    double x,y,z;

    Vector(double X = 0, double Y = 0, double Z = 0) : x(X), y(Y), z(Z) {}
    
    Vector distance(Vector);

    Vector operator+(Vector);
    Vector operator-(Vector);
};

