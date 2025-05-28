#include "gtest_lite.h"
#include "memtrace.h"
#include "Array.hpp"
#include "Vector.h"
#include "Particle.hpp"
#include "Simulation.hpp"

#include <iostream>
#include <stdexcept>
#include <sstream>


int main(void) {

    TEST(Array, print) 
    {
        Array<int> arr;
        for (int i = 0; i <= 10; i++)
            arr.insert(new int(i));
        
        std::stringstream out; 
        arr.print(out, ", ");
        EXPECT_EQ(std::string("0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10"), out.str())
        << "kiiras rossz\n";
    } END

    TEST(Array, insert1) 
    {
        Array<char> arr;
        arr.insert(new char('I'));
        arr.insert(new char('n'));
        arr.insert(new char('f'));
        arr.insert(new char('o'));
        arr.insert(new char('C'));
        arr.insert(new char('+'));
        arr.insert(new char('+'));

        std::stringstream out; 
        arr.print(out, "");

        EXPECT_EQ(std::string("InfoC++"), out.str())
        << "insert rossz formatum\n";


    } END

    TEST(Array, insert2)
    {
        Array<int> arr;
        for (size_t i = 0; i < 32; i++) {
            arr.insert(new int(i));
        }

        std::stringstream out;
        arr.print(out, ", ");

        std::stringstream check;
        for (size_t i = 0; i < 31; i++) {
            check << i << ", ";
        }
        check << 31;

        EXPECT_EQ(check.str(), out.str())
        << "insert rossz vagy nem bovul\n";

    } END

    
    TEST(Array, remove)
    {
        Array<int> arr; 
        for(int i = 0; i <= 100; i++)
            arr.insert(new int(i));
        
        std::stringstream arrayStr;
        arr.print(arrayStr, ", ");

        std::stringstream checkStr;
        for(int i = 0; i <= 99; i++)
            checkStr << i << ", ";
        checkStr << 100;

        EXPECT_EQ(checkStr.str(), arrayStr.str());

        for(int i = 0; i <= 90; i++) {
            arr.remove();
        }
        arrayStr.str("");
        arr.print(arrayStr, ", ");
    
        EXPECT_EQ("0, 1, 2, 3, 4, 5, 6, 7, 8, 9", arrayStr.str()) 
        << "remove rossz\n";

    } END

    TEST(Array, copy)
    {
        Array<char> arr;
        for (int i = 0; i < 10; i++) {
            arr.insert(new char('c'));
        }

        Array<char> arrConstruct(arr);
        Array<char> arrAssign;
        arrAssign = arr;

        EXPECT_EQ(arr, arrConstruct) << "copy constructor rossz\n";
        EXPECT_EQ(arr, arrAssign) << "copy assignment rossz\n";
 
    } END

    TEST(Array, operator[]) 
    { 
        Array<int> arr(10);
        for (int i = 0; i < 10; i++)
            arr.insert(new int(i));

        std::stringstream ss;
        arr.print(ss, ", ");

        EXPECT_EQ("0, 1, 2, 3, 4, 5, 6, 7, 8, 9", ss.str());

        EXPECT_THROW(arr[10], std::out_of_range const&) << "operator[] exception rossz (pozitiv)\n";
        EXPECT_THROW(arr[-1], std::out_of_range const&) << "operator[] exception rossz (negativ)\n";

    } END

    TEST(Array, operator==)
    {
        Array<int> arr(10);
        for (int i = 0; i < 10; i++)
            arr.insert(new int(i));
        
        Array<int> copy(arr);

        EXPECT_EQ(arr, copy) << "operator== rossz\n";
    } END


    TEST(Vector, all) 
    {
        Vector vec1(1, 2, 3);
        Vector vec2(3, 4, 0);
        Vector vecD(1.2, 3.4, 5.6); 

        EXPECT_FLOAT_EQ(5.0, vec2.size());
        EXPECT_EQ(Vector(4, 6, 3), vec1+vec2);
        EXPECT_EQ(Vector(1.8, 0.6, -5.6), vec2-vecD);
        EXPECT_EQ(Vector(2.4, 6.8, 11.2), vecD*2);
        EXPECT_EQ(Vector(1.5, 2, 0), vec2/2);
    } END

    TEST(Particle, all) 
    {
        Particle p(Vector(0,0,0), Vector(0,0,0), 1);
        
        EXPECT_EQ(1, p.getMass());
        EXPECT_EQ(Vector(0,0,0), p.getPos());
        EXPECT_EQ(Vector(0,0,0), p.getVel());

        p.applyForce(Vector(1.12,1,1), 1);
        EXPECT_EQ(Vector(1.12,1,1), p.getVel()); 

        p.move(1);
        EXPECT_EQ(Vector(1.12,1,1), p.getPos());

        std::fstream fs("test.dat", std::fstream::in | std::fstream::out);
        p.write(fs);
        Particle pcop;
        pcop.read(fs);

        EXPECT_EQ(p, pcop);
    } END


    TEST(Particle, forceWith)
    {
        Vector v1(3,3,3);
        Vector v2(4,3,3);

        Particle gp1(v1, v1, 1, true);
        Particle gp2(v2, v1, 1, true);

        EXPECT_EQ(Vector(1,0,0), gp1.forceWith(gp2));
        EXPECT_EQ(Vector(-1,0,0), gp2.forceWith(gp1));

        Particle* p1 = &gp1;
        Particle& p2 = gp2;

        EXPECT_EQ(Vector(1,0,0), p1->forceWith(p2));
        EXPECT_EQ(Vector(-1,0,0), p2.forceWith(*p1));

    } END

    TEST(Simulation, all) 
    {
        Simulation sim;
        Particle gp1(Vector(0,0,0), Vector(0,0,0), 1, 0, true);
        Particle gp2(Vector(1.113213,0,0), Vector(0,0,0), 1, 0, true);
        sim.addParticle(new Particle(gp1));
        sim.addParticle(new Particle(gp2));
        //sim.listParticles(std::cout);
        sim.step(1);
        //sim.listParticles(std::cout);

        std::stringstream ss;
        sim.write(ss);
        Simulation cop;
        cop.read(ss);

        EXPECT_EQ(sim, cop);


        std::ofstream ofs("test.dat", std::ofstream::binary);
        sim.write(ofs);
        ofs.close();

        std::ifstream ifs("test.dat", std::ifstream::binary);
        cop.read(ifs);
        ifs.close();

        EXPECT_EQ(sim, cop);
    } END
}