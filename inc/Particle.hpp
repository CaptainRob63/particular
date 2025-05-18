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

    // each particle necessarily belongs to a simulation instance
    const Simulation& simulation;
public:

    /**
     * @brief constructor
     * 
     * @param sim simulation particle belongs to
     * @param position position of particle
     * @param velocity velocity of particle
     * @param m mass of particle
     */
    Particle(const Simulation& sim,
             Vector position = Vector(0,0,0),
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
     * @brief calculates force acting on particle based on the simulation instance it belongs to
     */
    virtual Vector calcForces();

    /**
     * @brief adds velocity deltaV to velocity vector of particle
     * 
     * @param deltaV velocity to add to particle velocity
     */
    void addVelocity(Vector deltaV);
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
