#include "EMParticle.hpp"
#include "GravityParticle.hpp"
#include "Vector.h"
#include "constant.h"

EMParticle::EMParticle(Vector pos, Vector vel, double mass, double charge, bool grav) 
    : GravityParticle(pos, vel, mass, grav), charge(charge)
{}

Vector EMParticle::forceWith(const EMParticle& other) const
{
    if (charge == 0 || other.charge == 0) return Vector(0,0,0);

   Vector force(0,0,0);
   force = force + GravityParticle::forceWith(other); 

   Vector diff = other.getPos() - getPos();
   double r = diff.size();
   Vector dir = diff/r;

   force = force + dir * ((K*charge*other.charge) / r*r);
   return force;
}

void EMParticle::write(std::ostream& os) const
{
    GravityParticle::write(os);
    os << charge << std::endl;
}

void EMParticle::read(std::istream& is) 
{
    GravityParticle::read(is);
    (is >> charge).ignore(1);
}