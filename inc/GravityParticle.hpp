#ifndef GRAVITYPARTICLE_HPP
#define GRAVITYPARTICLE_HPP

#include "Particle.hpp"

class GravityParticle : Particle {
protected:
    bool isGravityInteracting;
public:
    virtual Vector calcForces();
};


#endif