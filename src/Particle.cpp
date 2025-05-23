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

void Particle::write(std::ostream& os) const
{
    os << mass << std::endl;
    os << pos.x << " " << pos.y << " " << pos.z << std::endl;
}

void Particle::read(std::istream is) 
{
    double temp;
    (is >> temp).ignore(1);
    (is >> pos.x >> pos.y >> pos.z).ignore(1);
}