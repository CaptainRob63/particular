#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Array.hpp"
#include "Particle.hpp"
class Simulation {
    Array<Particle> particles;
public:
    Simulation(Array<Particle> pa);
    Simulation(const Simulation& sim);
    Simulation& operator=(const Simulation& sim);

    void addParticle(Particle p);
    void removeParticle(size_t idx);
    void step();
};

#endif