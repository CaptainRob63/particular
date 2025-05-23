#include "Particle.hpp"
#include "Vector.h"
#include "Simulation.hpp"

Particle::Particle(Vector position, Vector velocity, double m)
    : pos(position), vel(velocity), mass(m)
{} 

Particle::Particle(const Particle& other) 
    : pos(other.pos), vel(other.vel), mass(other.mass) 
{}

Particle& Particle::operator=(const Particle& other) 
{
    pos = other.pos;
    vel = other.vel;
    mass = other.mass;
    return *this;
}   

Particle::~Particle() {}

void Particle::applyForce(Vector force) 
{
    vel = vel + force/mass;
}


std::ostream& operator<<(std::ostream& os, const Particle& p) 
{
    os << p.mass

    return os;
}