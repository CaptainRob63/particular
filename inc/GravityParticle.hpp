#ifndef GRAVITYPARTICLE_HPP
#define GRAVITYPARTICLE_HPP

#include "Particle.hpp"

/**
 * @brief gravity interacting particle with overwritten forceWith() 
 */
class GravityParticle : public Particle {
protected:
    bool isGravityInteracting;
public:

    /**
     * @brief constructor
     * 
     * @param pos position vector
     * @param vel velocity vector
     * @param mass mass
     * @param grav true if particle takes part in gravity interaction (affects/is affected by).
     */
    GravityParticle(Vector pos = Vector(0,0,0), 
                    Vector vel = Vector(0,0,0), 
                    double mass = 1,
                    bool grav = false);

    
    /**
     * @brief assignment operator= 
     * 
     * @param p other particle
     * @return GravityParticle& *this for chaining
     */
    GravityParticle& operator=(const GravityParticle& other); 

    
    /**
     * @brief grav getter
     * 
     * @return grav 
     */
    bool getGrav() const { return isGravityInteracting; } 

    /**
     * @brief gravity force calculation 
     * 
     * @param other particle to calculate interaction with
     * @return Vector force vector pointing towards other parameter vector
     */
    virtual Vector forceWith(const GravityParticle& other) const;
    using Particle::forceWith;

    /**
     * @brief particle write method overwrite 
     * 
     * @param os std::ostream to write to
     */
    virtual void write(std::ostream& os) const;

    /**
     * @brief particle read method overwrite 
     * 
     * @param is std::istream to read from
     */
    virtual void read(std::istream& is);
};


#endif