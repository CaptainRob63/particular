#include <iostream>
#include "Simulation.hpp"


int main(int argc, const char** argv) 
{
    Simulation sim;

    while (true)
    {
        std::cout   << "1 list particles" << std::endl 
                    << "2 add particle"   << std::endl
                    << "3 remove particle"<< std::endl
                    << "4 simulate"       << std::endl
                    << "5 exit"           << std::endl;
        
        int select = 0;
        std::cin >> select;
        if (select < 1 || select > 5) 
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
            std::cout << ""
            break;

        case 3:
            break;       

        case 4:
            break;

        case 5:
            break;

        default:
            break;
        }
    }
}