#include "Simulation.hpp"

Simulation::Simulation()
    : time(0)
{}

void Simulation::listParticles(std::ostream& os)
{
    particles.print(os, "\n");
}

void Simulation::addParticle(Particle* p)
{
    particles.insert(p);
}

void Simulation::removeParticle(size_t idx)
{
    particles.remove(idx);
}

void Simulation::step(double time) 
{
    for (size_t i = 0; i < particles.getSize(); ++i)
        for (size_t j = 0; j < particles.getSize(); ++j)
        {
            if(i == j) continue;

            Vector force = particles[i].forceWith(particles[j]);
            particles[i].applyForce(force, time);
        }

    for (size_t i = 0; i < particles.getSize(); ++i)
        particles[i].move(time);
}