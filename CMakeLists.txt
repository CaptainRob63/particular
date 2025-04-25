cmake_minimum_required(VERSION 3.28)
project(Particular)
add_compile_options(-Wall -Werror -pedantic -g)

add_executable(Particular src/main.cpp)
target_include_directories(Particular PRIVATE inc)
