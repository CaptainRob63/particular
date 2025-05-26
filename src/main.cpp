#include <iostream>
#include "Simulation.hpp"
#include <fstream>


int main(int argc, const char** argv) 
{
    Simulation sim;

    while (true)
    {
        std::cout   << "1 list particles" << std::endl 
                    << "2 add particle"   << std::endl
                    << "3 remove particle"<< std::endl
                    << "4 simulate"       << std::endl
                    << "5 from file"       << std::endl
                    << "6 exit"           << std::endl;
        
        int select = 0;
        std::cin >> select;

        // validation
        if (std::cin.fail()) 
        {
            std::cerr << "selection format invalid" << std::endl;
            return 1;
        }

        // flush stdin
        char flush[100];
        std::cin.getline(flush, 100);

        // bounds check
        if (select < 1 || select > 6) 
        {
            std::cout << "invalid selection!" << std::endl;
            continue;
        }


        switch (select)
        {
            case 1 :
                sim.listParticles(std::cout);
                break;
            
            case 2:
                try 
                {
                    std::cout << "pos (xyz):" << std::endl;
                    Vector pos;
                    std::cin >> pos.x >> pos.y >> pos.z;

                    std::cout << "vel (xyz):" << std::endl;
                    Vector vel;
                    std::cin >> vel.x >> vel.y >> vel.z;

                    std::cout << "mass:" << std::endl;
                    double mass;
                    std::cin >> mass;

                    std::cout << "charge:" << std::endl;
                    double charge;
                    std::cin >> charge;

                    std::cout << "gravity (bool) :" << std::endl;
                    bool grav;
                    std::cin >> grav;

                    sim.addParticle(new Particle(pos, vel, mass, charge, grav));
                } 
                catch (...) 
                {
                    std ::cout << "bad input!" << std::endl;
                    continue;
                }

                break;

            case 3:
                std::cout << "which particle? (negative for exit)" << std::endl;
                int select;
                std::cin >> select;
                if (select < 0) break;

                try {sim.removeParticle(select);}
                catch (std::out_of_range& e)
                {
                    std::cout << e.what() << std::endl;
                    continue;
                }
                break;       

            case 4:
                {
                std::cout << "length, timestep? (l ts)" << std::endl;
                double length, step;
                std::cin >> length >> step;

                std::ofstream os("sim.dat", std::ofstream::out );
                sim.write(os);
                for (double t0 = 0; t0 < length; t0 += step)
                {
                    sim.step(step);
                    sim.write(os);
                }
                os.close();
                }
                break;

            case 5:
                {
                std::ifstream is("sim.dat", std::ifstream::in);

                is.seekg(-1, is.end);
                while (is.peek() != '{') 
                {
                    std::cout << char(is.peek());
                    //std::cout << is.peek();
                    is.seekg(-1, is.cur);
                }
                sim.read(is);
                is.close();
                }
                break;

            case 6:
                return 0;
                break;

            default:
                break;
        }
    }
    return 0;
}