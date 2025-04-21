#ifndef PARTICLEARRAY_HPP
#define PARTICLEARRAY_HPP

#include "Array.hpp"
#include "Particle.hpp"
#include "Simulation.hpp"


class ParticleArray : Array<Particle> {
    const Simulation& simulation;
}

#endif