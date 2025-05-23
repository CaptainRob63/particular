#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vector.h"
#include "Simulation.hpp"

#include <ostream>

class Particle 
{
    Vector pos;
    Vector vel;
    double mass;

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
             double m = 1); 

    /**
     * @brief copy constructor
     */
    Particle(const Particle&);

    /**
     * @brief virtual destructor
     */
    virtual ~Particle();

    /**
     * @brief mass getter 
     * 
     * @return double mass attribute
     */
    double getMass() const { return mass; }    

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
     * @brief copy assignment
     */
    Particle& operator=(const Particle&);    

    /**
     * @brief calculates force between two particles. pure virtual 
     * 
     * @param other other particle
     * @return Vector force vector
     */
    virtual Vector forceWith(const Particle& other) = 0;

    /**
     * @brief applies force to particle
     * 
     * @param force force to apply
     **/
    void applyForce(Vector force);

    /**
     * @brief write to ostream 
     * 
     * @param os std::ostream to write to
     */
    virtual void write(std::ostream& os) const;

    /**
     * @brief read from ostream 
     * 
     * @param is std::istream to read from
     */
    virtual void read(std::istream is);

};

#endif