#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vector.hpp"
#include "Simulation.hpp"

#include <ostream>

class Particle {
    Vector pos;
    Vector vel;
    double mass;
    const Simulation& simulation;
public:
    Particle(Vector position = Vector(0,0,0),
             Vector velocity = Vector(0,0,0),
             double m = 1,
             const Simulation& sim); 

    Particle(const Particle&);
    Particle& operator=(const Particle&);    
    virtual ~Particle();

    virtual Vector calcForces();
    void addVelocity(Vector deltaV);
   };

std::ostream& operator<<(std::ostream& os, ParticleArray pa);

#endif
