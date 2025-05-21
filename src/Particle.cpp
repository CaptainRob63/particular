#include "Particle.hpp"
#include "Vector.h"
#include "Simulation.hpp"

    Particle::Particle(Vector position, Vector velocity, double m)
        : pos(position), vel(velocity), mass(m)
    {

    } 

    Particle::Particle(const Particle& other) 
        : pos(other.pos), vel(other.vel), mass(other.mass) 
    {

    }

    Particle& Particle::operator=(const Particle& other) {
        pos = other.pos;
        vel = other.vel;
        mass = other.mass;
    }   

    Particle::~Particle() {}

    Vector Particle::forceWith(const Particle& other) {}
 
    void Particle::applyForce(Vector force) {
        vel += force/mass;
    }