#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "ParticleArray.hpp"
class Simulation {
    ParticleArray particles;
public:
    Simulation(ParticleArray pa);
    Simulation(const Simulation& sim);
    Simulation& operator=(const Simulation& sim);

    void addParticle(Particle p);
    void removeParticle(size_t idx);
    void step();
};

#endif