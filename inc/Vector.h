#ifndef VECTOR_H
#define VECTOR_H

/**
 * @brief physics type vector3d 
 * 
 */
struct Vector {
    double x,y,z;

    /**
     * @brief vector constructor
     * 
     * @param X x coordinate
     * @param Y y coordinate
     * @param Z z coordinate
     */
    Vector(double X = 0, double Y = 0, double Z = 0);
   
    /**
     * @brief norm of vector (pythagoras) 
     * 
     * @return double norm
     */
    double size();

    /**
     * @brief field by field equality 
     * 
     * @param other vector to compare
     * @return bool 
     */
    bool operator==(Vector other);

    /**
     * @brief vector addition
     * 
     * @param other vector to sum with
     * @return Vector sum of vectors
     */
    Vector operator+(Vector other);

    /**
     * @brief vector subtraction
     * 
     * @param vector to subtract
     * @return Vector difference of vectors
     */
    Vector operator-(Vector other);
    
    /**
     * @brief scalar multiplication
     * 
     * @param scalar scalar to multiply vector by
     * @return Vector scaled vector
     */
    Vector operator*(double scalar);

    /**
     * @brief scalar division 
     * 
     * @param scalar scalar to divide by
     * @return Vector scaled vector
     */
    Vector operator/(double scalar);
};

#endif // VECTOR_H