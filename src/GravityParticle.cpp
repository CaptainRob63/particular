#include "GravityParticle.hpp"
#include "constant.h"

GravityParticle::GravityParticle(Vector pos, Vector vel, double mass, bool grav)
    : Particle(pos, vel, mass), isGravityInteracting(grav)
{}

GravityParticle& GravityParticle::operator=(const GravityParticle& other)
{
    Particle::operator=(other);
    isGravityInteracting = other.isGravityInteracting;
    return *this;
} 

Vector GravityParticle::forceWith(const GravityParticle& other) const
{
    // interaction is both ways
    if (!other.isGravityInteracting || !isGravityInteracting) return Vector(0,0,0);

    Vector diff(other.getPos() - getPos());
    double r = diff.size();
    Vector dir = diff/r;

    return dir * ( (G*getMass()*other.getMass()) / r*r);
}


void GravityParticle::write(std::ostream& os) const
{
    Particle::write(os);
    os << isGravityInteracting << std::endl;
}

void GravityParticle::read(std::istream& is)
{
    Particle::read(is);
    (is >> isGravityInteracting).ignore(1);
}

