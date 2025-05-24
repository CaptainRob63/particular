#include "GravityParticle.hpp"
#include "constant.h"

Vector GravityParticle::forceWith(const Particle& other) const
{
    Vector diff(other.getPos() - getPos());
    double r = diff.size();
    Vector dir = diff/r;

    Vector force;
    force = dir * ( (G*getMass()*other.getMass()) / r*r);
    return force;
}