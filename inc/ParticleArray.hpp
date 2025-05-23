#ifndef PARTICLEARRAY_HPP
#define PARTICLEARRAY_HPP

#include "Array.hpp"
#include "Particle.hpp"
#include "Simulation.hpp"


class ParticleArray : public Array<Particle> {
    const Simulation& simulation;
};

#endif