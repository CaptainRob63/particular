#include "Particle.hpp"
#include "Vector.h"
#include "Simulation.hpp"

    Particle::Particle(const Simulation& sim, Vector position, Vector velocity, double m)
        : simulation(sim), pos(position), vel(velocity), mass(m)
    {

    } 

    Particle::Particle(const Particle& other) 
        : pos(other.pos), vel(other.vel), mass(other.mass), simulation(other.simulation)
    {

    }

    Particle& Particle::operator=(const Particle&) {}   

    Particle::~Particle() {}

    Vector Particle::calcForces() {}
    void Particle::addVelocity(Vector deltaV) {}