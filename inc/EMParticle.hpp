#ifndef EMPARTICLE_HPP
#define EMPARTICLE_HPP

#include "GravityParticle.hpp"
#include "Particle.hpp"

class EMParticle : GravityParticle {
protected:
    double charge;
public:
    

    virtual Vector forceWith(const Particle& other) const;
};


#endif
