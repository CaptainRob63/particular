#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <fstream>
#include "Simulation.hpp"

class FileHandler {
   std::fstream fs; 
public:
    FileHandler(const char* filename);
    void writeState(const Simulation& sim);
    Simulation& readState(void);
};

#endif