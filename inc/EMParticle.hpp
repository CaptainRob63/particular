#ifndef EMPARTICLE_HPP
#define EMPARTICLE_HPP

#include "GravityParticle.hpp"

class EMParticle : GravityParticle {
protected:
    double charge;
public:
    virtual Vector calcForces();
};


#endif
