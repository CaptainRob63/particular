cmake_minimum_required(VERSION 3.28)
project(Particular)
add_compile_options(-Wall -Werror -pedantic -g)

# main source files
add_executable(Particular src/main.cpp
                          src/Array.cpp)


# includes
target_include_directories(Particular PRIVATE inc)

# testing
add_executable(Test 
                    # test sources
                    test/test.cpp
                    test/memtrace.cpp
                    
                    # main sources
                    src/Array.cpp)

target_include_directories(Test PRIVATE inc)
enable_testing()
add_test(NAME Test COMMAND Test)

