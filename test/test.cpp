#include "gtest_lite.h"
#include "memtrace.h"
#include "Array.hpp"

#include <iostream>
#include <stdexcept>
#include <sstream>

#define MEMTRACE

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

        std::stringstream out; 
        arr.print(out, "");

        EXPECT_EQ(std::string("InfoC"), out.str())
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

    } END

}