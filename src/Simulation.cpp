#include "Simulation.hpp"

Simulation::Simulation()
{}

bool Simulation::operator==(const Simulation& other) const
{
    return (particles == other.particles);
}

void Simulation::listParticles(std::ostream& os)
{
    os << particles;
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

void Simulation::write(std::ostream& os) const 
{
    os << "{" << std::endl;
    particles.write(os);
    os << "}" << std::endl << std::endl;;
}

void Simulation::read(std::istream& is) 
{
    is.ignore(2);
    particles.read(is);
    is.ignore(3);
}

std::ostream& operator<<(std::ostream& os, const Simulation& sim)
{
    return os << sim.getParticles();
}