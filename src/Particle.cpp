#include "Particle.hpp"
#include "Vector.h"
#include "Simulation.hpp"
#include "constant.h"

Particle::Particle(Vector position, Vector velocity, double m, double ch, bool grav)
    : pos(position), vel(velocity), mass(m), charge(ch), isGravityInteracting(grav)
{} 

Particle::Particle(const Particle& other) 
    : pos(other.pos), vel(other.vel), mass(other.mass), charge(other.charge), isGravityInteracting(other.isGravityInteracting) 
{}

Particle& Particle::operator=(const Particle& other) 
{
    pos = other.pos;
    vel = other.vel;
    mass = other.mass;
    charge = other.charge;
    isGravityInteracting = other.isGravityInteracting;
    return *this;
}   

Particle::~Particle() {}

bool Particle::operator==(const Particle& other) const
{
    return (pos == other.pos && 
            vel == other.vel && 
            abs(mass - other.mass) <= EPSILON &&
            abs(charge - other.charge) <= EPSILON &&
            isGravityInteracting == other.isGravityInteracting);
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
    os << pos.x << " " << pos.y << " " << pos.z << std::endl;
    os << vel.x << " " << vel.y << " " << vel.z << std::endl;
    os << mass << std::endl;
    os << charge << std::endl;
    os << isGravityInteracting << std::endl;
}

void Particle::read(std::istream& is) 
{
    (is >>
    pos.x >>
    pos.y >>
    pos.z)
    .ignore(1);

    (is >> vel.x >> vel.y >> vel.z).ignore(1);
    (is >> mass).ignore(1);
    (is >> charge).ignore(1);
    (is >> isGravityInteracting).ignore(1);
}


std::ostream& operator<<(std::ostream& os, const Particle& p) 
{
    os << "pos: " << p.getPos().x << " " << p.getPos().y << " " << p.getPos().z << std::endl;
    os << "vel: " << p.getVel().x << " " << p.getVel().y << " " << p.getVel().z << std::endl;
    os << "mass: " << p.getMass() << std::endl;
    os << "charge: " << p.getCharge() << std::endl;
    os << "gravity: " << std::boolalpha << p.getGrav() << std::noboolalpha << std::endl << std::endl;
    return os;
}

Vector Particle::forceWith(const Particle& other) const
{
    Vector diff(other.getPos() - getPos());
    double r = diff.size();
    Vector dir = diff/r;

    Vector gForce, emForce;

    // interaction is both ways
    if (other.isGravityInteracting && isGravityInteracting) 
        gForce = dir * ( (G*getMass()*other.getMass()) / r*r);

    emForce =  dir * ((K*charge*other.charge) / r*r);

    return gForce + emForce;
}