#include "GravityParticle.hpp"
#include "constant.h"

GravityParticle::GravityParticle(Vector pos, Vector vel, double mass, bool grav)
    : Particle(pos, vel, mass), isGravityInteracting(grav)
{}

Vector GravityParticle::forceWith(const GravityParticle& other) const
{
    // interaction is both ways
    if (other.isGravityInteracting == false) return Vector(0,0,0);

    Vector diff(other.getPos() - getPos());
    double r = diff.size();
    Vector dir = diff/r;

    return dir * ( (G*getMass()*other.getMass()) / r*r);
}