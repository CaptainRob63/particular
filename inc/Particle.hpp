#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vector.h"
#include <ostream>

/**
 * @brief non-interacting particle class. 
 * 
 */
class Particle 
{
    Vector pos;
    Vector vel;
    double mass;
    double charge;
    bool isGravityInteracting;

public:

    /**
     * @brief constructor
     * 
     * @param position position of particle
     * @param velocity velocity of particle
     * @param m mass of particle
     */
    Particle(Vector position = Vector(0,0,0),
             Vector velocity = Vector(0,0,0),
             double m = 1,
             double ch = 0,
             bool grav = false); 

    /**
     * @brief copy constructor
     */
    Particle(const Particle&);

    /**
     * @brief virtual destructor
     */
    virtual ~Particle();
    
    /**
     * @brief copy assignment
     */
    Particle& operator=(const Particle&);    

    /**
     * @brief mass getter 
     * 
     * @return double mass attribute
     */
    double getMass() const { return mass; }    

     /**
     * @brief charge getter
     * 
     * @return double charge
     */
    double getCharge() const { return charge; }

    /**
     * @brief grav getter
     * 
     * @return grav 
     */
    bool getGrav() const { return isGravityInteracting; } 

    /**
     * @brief position getter
     * 
     * @return Vector position attribute
     */
    Vector getPos() const { return pos; }

    /**
     * @brief velocity getter
     * 
     * @return Vector vel attribute
     */
    Vector getVel() const { return vel; }

    /**
     * @brief equality operator 
     * @param other vector to compare
     */
    bool operator==(const Particle& other) const;

    bool operator!=(const Particle& other) const { return !operator==(other);}

    /**
     * @brief calculates force between two particles.
     * 
     * @param other other particle
     * @return Vector force vector
     */
    Vector forceWith(const Particle& other) const; 

    /**
     * @brief applies force to particle
     * 
     * @param force force to apply
     * @param time time to apply force for
     **/
    void applyForce(Vector force, double time);

    /**
     * @brief move the particle based on its velocity vector 
     * 
     * @param time how much time to move the particle for
     */
    void move(double time);

    /**
     * @brief write to ostream 
     * 
     * @param os std::ostream to write to
     */
    void write(std::ostream& os) const;

    /**
     * @brief read from ostream 
     * 
     * @param is std::istream to read from
     */
    void read(std::istream& is);

};

/**
 * @brief print to ostream operator<< (just for gtest_lite) 
 * 
 * @param os std::ostream to print to
 * @param p particle const& to print
 * @return std::ostream& for chaining
 */
std::ostream& operator<<(std::ostream& os, const Particle& p);

#endif