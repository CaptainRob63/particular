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
     * @brief list particles to std::ostream 
     * 
     * @param os std::ostream to list
     */
    void listParticles(std::ostream& os);

    /**
     * @brief add a particle to simulation 
     * 
     * @param p particle to add
     */
    void addParticle(Particle p);

    /**
     * @brief remove a particle from simulation 
     * 
     * @param idx index of particle to remove
     */
    void removeParticle(size_t idx);

    /**
     * @brief steps the simulation a set time
     * 
     * @param t time to step
     */
    void step(double t);
};

#endif