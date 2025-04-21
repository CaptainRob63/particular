#ifndef EMPARTICLE_HPP
#define EMPARTICLE_HPP

#include "Particle.hpp"

class EMParticle : Particle {
protected:
    double charge;
public:
    Vector calcForces();
};


#endif