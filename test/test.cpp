#include "gtest_lite.h"
#include "Array.hpp"

#include <iostream>
#include <stdexcept>
#include <sstream>


int main(void) {

    TEST(Array, print) {

        Array<int> arr;
        for (int i = 0; i <= 10; i++)
            arr.insert(i);
        
        std::stringstream out; 
        out << arr;
        EXPECT_EQ(std::string("1, 2, 3, 4, 5, 6, 7, 8, 9, 10"), out.str()) << "kiiras rossz";

    } END

}