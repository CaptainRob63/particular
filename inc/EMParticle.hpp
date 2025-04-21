#ifndef EMPARTICLE_HPP
#define EMPARTICLE_HPP

#include "Particle.hpp"

class EMParticle : Particle {
protected:
    double charge;
public:
    virtual Vector calcForces();
};


#endif