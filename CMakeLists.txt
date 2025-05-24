cmake_minimum_required(VERSION 3.28)
project(Particular)
add_compile_options(-Wall -Werror -pedantic -g)


# main source files
set(SOURCES src/Particle.cpp
            src/Vector.cpp
            src/memtrace.cpp
            src/GravityParticle.cpp
            src/EMParticle.cpp
            )

# main bin
add_executable(Particular src/main.cpp ${SOURCES})

# includes
target_include_directories(Particular PRIVATE inc)

# definitions
add_compile_definitions(MEMTRACE)

# testing

    # test sources
    set(TEST_SOURCES test/test.cpp
                     )
    
    # test bin
    add_executable(Test ${SOURCES} ${TEST_SOURCES})

    target_include_directories(Test PRIVATE inc)
    enable_testing()
    add_test(NAME Test COMMAND Test)

