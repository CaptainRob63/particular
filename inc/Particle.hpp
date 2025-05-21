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
     * @param sim simulation particle belongs to
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
     * @brief copy assignment
     */
    Particle& operator=(const Particle&);    

    /**
     * @brief virtual destructor
     */
    virtual ~Particle();

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
};

/**
 * @brief print to ostream 
 * 
 * @param os 
 * @param pa 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, ParticleArray pa);

#endif
