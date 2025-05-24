#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Array.hpp"
#include "Particle.hpp"
class Simulation {
    double time;
    Array<Particle> particles;
public:
    
    /**
     * @brief simulation constructor
     */
    Simulation();

    /**
     * @brief steps the simulation a set time
     * 
     * @param t time to step
     */
    void step(double t);
};

#endif