#include "Particle.hpp"
#include "Vector.h"
#include "Simulation.hpp"
#include "constant.h"

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

bool Particle::operator==(const Particle& other) const
{
    return (pos == other.pos || vel == other.vel || abs(mass - other.mass) <= EPSILON);
}

void Particle::applyForce(Vector force, double time) 
{
    vel = vel + (force/mass) * time;
}


void Particle::move(double time) 
{
    pos = pos + vel*time;
}

void Particle::write(std::ostream& os) const
{
    os << mass << std::endl;
    os << pos.x << " " << pos.y << " " << pos.z << std::endl;
}

void Particle::read(std::istream& is) 
{
    double temp;
    (is >> temp).ignore(1);
    (is >> pos.x >> pos.y >> pos.z).ignore(1);
}


std::ostream& operator<<(std::ostream& os, const Particle& p) 
{
    p.write(os);
    return os;
}