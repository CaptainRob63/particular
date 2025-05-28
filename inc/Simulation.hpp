#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Array.hpp"
#include "Particle.hpp"

/**
 * @brief wrapper and manager for all simulation entities (currently only particle array) 
 * 
 */
class Simulation {
    Array<Particle> particles;
public:
    
    /**
     * @brief simulation constructor
     */
    Simulation();

    /**
     * @brief Get the Particles object (const)
     * 
     * @return const Array<Particle> 
     */
    const Array<Particle> getParticles() const { return particles; }

    /**
     * @brief comparison 
     * 
     * @param other other simulation 
     */
    bool operator==(const Simulation& other) const;

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
    void addParticle(Particle* p);

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

    /**
     * @brief write sim to ostream 
     * @param os ostream 
     */
    void write(std::ostream& os) const;

    /**
     * @brief read sim from istream 
     * 
     * @param is istream
     */
    void read(std::istream& is);
    
};

std::ostream& operator<<(std::ostream& os, const Simulation& sim);


#endif