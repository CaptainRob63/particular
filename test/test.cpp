#include "gtest_lite.h"
#include "memtrace.h"
#include "Array.hpp"
#include "Vector.h"
#include "Particle.hpp"

#include <iostream>
#include <stdexcept>
#include <sstream>


int main(void) {

    TEST(Array, print) 
    {
        Array<int> arr;
        for (int i = 0; i <= 10; i++)
            arr.insert(i);
        
        std::stringstream out; 
        out << arr;
        EXPECT_EQ(std::string("0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10"), out.str())
        << "kiiras rossz\n";
    } END

    TEST(Array, insert1) 
    {
        Array<char> arr;
        arr.insert('I');
        arr.insert('n');
        arr.insert('f');
        arr.insert('o');
        arr.insert('C');
        arr.insert('+');
        arr.insert('+');

        std::stringstream out; 
        arr.print(out, "");

        EXPECT_EQ(std::string("InfoC++"), out.str())
        << "insert rossz formatum\n";


    } END

    TEST(Array, insert2)
    {
        Array<int> arr;
        for (size_t i = 0; i < 32; i++) {
            arr.insert(i);
        }

        std::stringstream out;
        out << arr;

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
            arr.insert(i);
        
        std::stringstream arrayStr;
        arrayStr << arr;

        std::stringstream checkStr;
        for(int i = 0; i <= 99; i++)
            checkStr << i << ", ";
        checkStr << 100;

        EXPECT_EQ(checkStr.str(), arrayStr.str());

        for(int i = 0; i <= 90; i++) {
            arr.remove();
        }
        arrayStr.str("");
        arrayStr << arr;
    
        EXPECT_EQ("0, 1, 2, 3, 4, 5, 6, 7, 8, 9", arrayStr.str()) 
        << "remove rossz\n";

    } END

    TEST(Array, copy)
    {
        Array<char> arr;
        for (int i = 0; i < 10; i++) {
            arr.insert('c');
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
            arr.insert(i);

        std::stringstream ss;
        ss << arr;

        EXPECT_EQ("0, 1, 2, 3, 4, 5, 6, 7, 8, 9", ss.str());

        EXPECT_THROW(arr[10], std::out_of_range const&) << "operator[] exception rossz (pozitiv)\n";
        EXPECT_THROW(arr[-1], std::out_of_range const&) << "operator[] exception rossz (negativ)\n";

    } END

    TEST(Array, operator==)
    {
        Array<int> arr(10);
        for (int i = 0; i < 10; i++)
            arr.insert(i);
        
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

        p.applyForce(Vector(1,1,1));
        EXPECT_EQ(Vector(1,1,1), p.getVel()); 

        std::stringstream os;
        p.write(os);
        Particle pcop;
        pcop.read(os);

        EXPECT_EQ(p, pcop);
    } END
}