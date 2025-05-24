#ifndef EMPARTICLE_HPP
#define EMPARTICLE_HPP

#include "GravityParticle.hpp"
#include "Particle.hpp"

class EMParticle : public GravityParticle {
protected:
    double charge;
public:
    
    /**
     * @brief constructor
     * 
     * @param pos position vector
     * @param vel velocity vector
     * @param mass mass
     * @param charge charge
     * @param grav true if particle takes part in gravity interaction (affects/is affected by).
     */
    EMParticle( Vector pos = Vector(0,0,0), 
                Vector vel = Vector(0,0,0), 
                double mass = 1,
                double charge = 0,
                bool grav = false);

    
    /**
     * @brief charge getter
     * 
     * @return double charge
     */
    double getCharge() const { return charge; }


    /**
     * @brief charge + gravity force calculation 
     * 
     * @param other 
     * @return Vector force pointing towards other 
     */
    Vector forceWith(const EMParticle& other) const;
};


#endif
