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
     * @brief gravity force calculation 
     * 
     * @param other particle to calculate interaction with
     * @return Vector force vector pointing towards other parameter vector
     */
    virtual Vector forceWith(const Particle& other) const;
};


#endif