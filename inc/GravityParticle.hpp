#ifndef GRAVITYPARTICLE_HPP
#define GRAVITYPARTICLE_HPP

#include "Particle.hpp"

/**
 * @brief gravity interacting particle with overwritten forceWith() 
 */
class GravityParticle : Particle {
protected:
    bool isGravityInteracting;
public:

    /**
     * @brief constructor
     * 
     * @param pos position vector
     * @param vel velocity vector
     * @param mass mass
     * @param grav true if particle takes part in gravity interaction (affects/is affected by).
     */
    GravityParticle(Vector pos = Vector(0,0,0), 
                    Vector vel = Vector(0,0,0), 
                    double mass = 1,
                    bool grav = false);

    
    /**
     * @brief gravity force calculation 
     * 
     * @param other particle to calculate interaction with
     * @return Vector force vector pointing towards other parameter vector
     */
    Vector forceWith(const GravityParticle& other) const;
};


#endif