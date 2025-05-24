#include "Simulation.hpp"

Simulation::Simulation()
    : time(0)
{}

void Simulation::step(double time) 
{
    for (size_t i = 0; i < particles.getSize(); ++i)
        for (size_t j = 0; j < particles.getSize(); ++j)
        {
            if(particles[i] == particles[j]) continue;

            Vector force = particles[i].forceWith(particles[j]);
            particles[i].applyForce(force);
        }

    for (size_t i = 0; i < particles.getSize(); ++i)
        particles[i].step(time);
}