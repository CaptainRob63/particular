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
}